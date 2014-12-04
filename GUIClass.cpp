#include "Manager.h"
#include "PurgeItem.h"
#include <time.h>
//#include "TimeComparer.cpp"

/**
This is the main form for the dashboard.  It contains all the things necessary to keep it working.
This includes list limiting, events, and date math.
In the future, hope to move date math to different class for better readability.
Jason Fiduk and Craig Pennell
*/
namespace dash {
	using namespace System;
	using namespace Manage;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;


	public ref class GUIClass : public System::Windows::Forms::Form, public IComparer
	{
	private: static const time_t MINUTE_INTERVAL = 60;
	private: static const time_t HOUR_INTERVAL = 60 * MINUTE_INTERVAL;

    // Any records fetched before this interval needs to be removed (in seconds) 
	//private: static const time_t PURGE_AGE_INTERVAL = 6 * HOUR_INTERVAL;
			 private: static  time_t PURGE_AGE_INTERVAL = MINUTE_INTERVAL;
	// How often we check for old records (in seconds)
	private: static const time_t CHECK_PURGE_AGE_INTERVAL = MINUTE_INTERVAL;

    // Max number of records permitted in the grid
	private:  static time_t PURGE_SIZE_MAX_ROWS = 1;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: static array<Object^, 2>^ TestArray = gcnew array<Object^, 2>(4, 2); //stores tests from dash.cpp
	private: static int  ListLimiter; //how many minutes or people to limit list to.
	private: static bool  ListLimiterType = true; //sets list limiter to minutes on initial call.
	private: System::Windows::Forms::Timer^ purgeAgeTimer;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private:  System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  visibilityToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  privateModeToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  publicModeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testManagerToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox1;
	//delegate used to safely add values to the grid from the seperate client thread.
	public: delegate void AddItemGrid(array<System::String^>^ arr);
		AddItemGrid^ myDelegate;

	public:
		/**
		Constructor. 
		Sets testArray to global variable and calls init to start the form.
		*/
		GUIClass(array<Object^, 2>^ tests){
			this->TestArray = tests;
			init();
		}

	private:
		/**
		Used for purging data after a certain amount of time.
		Checks the time the data was added to the table, in last column of table, and compares it to the current
		If its past that time we delete it.
		Craig Pennell
		*/
		void TimerPurgeAgeProcessor(Object^, EventArgs^) {
			time_t currentTime;
			time(&currentTime);
			for (int i = this->dataGridView1->Rows->Count - 1; i > -1; i--) {
				DataGridViewRow^ row = this->dataGridView1->Rows[i];
				DataGridViewCell^ cell = row->Cells[row->Cells->Count - 1];
				if (cell->Value != nullptr) {
					time_t createTime = (time_t)cell->Value;
					if (currentTime - createTime >= PURGE_AGE_INTERVAL) {
						this->dataGridView1->Rows->RemoveAt(i);
					}
				}
			}

			dataGridView1->PerformLayout();
		}
		/**
		Implemented compare method from ICompare.
		Compares values of 2 rows to see which came first.
		This is used in TimerPurgeSizeProcessor for the SortedList
		Craig Pennell
		*/
		virtual int compare(Object^ a, Object^ b) sealed = IComparer::Compare{
			PurgeItem^ pa = (PurgeItem^)a;
			PurgeItem^ pb = (PurgeItem^)b;
			if (pa->getTime() == pb->getTime()) {
				return pa->getIndex() - pb->getIndex();
			}
			else {
				return pa->getTime() - pb->getTime();
			}
		}
		/**
		Called every time we add a row.  If the dashboard is above the max number of rows,
		this checks all the current rows to see which is the oldest, and deletes it/them.
		Craig Pennell
		*/
		void TimerPurgeSizeProcessor() {
			if (this->dataGridView1->Rows->Count-1 <= PURGE_SIZE_MAX_ROWS) {
				return;
			}

			SortedList^ ageToIndex = gcnew SortedList(this); 
			//Adds all rows to sortedList, and sorts them based on oldest
			for (int i = this->dataGridView1->Rows->Count - 2; i > -1; i--) {
				DataGridViewRow^ row = this->dataGridView1->Rows[i];
				DataGridViewCell^ cell = row->Cells[row->Cells->Count -1];
				if (cell->Value != nullptr) {
					ageToIndex->Add(gcnew PurgeItem((time_t)cell->Value, cell->RowIndex), nullptr);
				}
			}

			if (ageToIndex->Count < 1) {
				return;
			}

			SortedList^ indexToAge = gcnew SortedList;
			//takes the previous sorted list and takes out how ever many old ones to get below the max
			for (int i = 0; i < ageToIndex->Count - (PURGE_SIZE_MAX_ROWS); i++) {
				PurgeItem^ key = (PurgeItem^)ageToIndex->GetKey(i);
				indexToAge->Add(key->getIndex(), key->getTime());
			}
			//deletes the rows that were picked from the sorted list.
			for (int i = indexToAge->Count-1; i > -1; i--) {
				this->dataGridView1->Rows->RemoveAt((int)indexToAge->GetKey(i));
			}
			cout << dataGridView1->Rows->Count << endl;
			dataGridView1->PerformLayout();

		}
		/**
		Initializes the dashboard.
		The dashboard contains a datagridview for the table
		Visibilty menu options to show the private or public name.
		Menu option to open the Manager
		A search bar
		Timers to check the list size.
		Jason Fiduk and Craig Pennell
		*/
		void init(){
			this->purgeAgeTimer = (gcnew System::Windows::Forms::Timer());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->visibilityToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->privateModeToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->publicModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testManagerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			myDelegate= gcnew AddItemGrid(this,&dash::GUIClass::addRow);
			this->menuToolStripMenuItem->Text = L"Menu";
			this->visibilityToolStripMenuItem1->Text = L"Visibility";
			this->privateModeToolStripMenuItem1->Text = L"Private Mode";
			this->publicModeToolStripMenuItem->Text = L"Public Mode";
			this->ListLimiter = 1;
			this->publicModeToolStripMenuItem->Checked = true;
			this->testManagerToolStripMenuItem->Text = L"Manager";
			this->menuStrip1->Items->Add(menuToolStripMenuItem);
			this->menuToolStripMenuItem->DropDownItems->Add(visibilityToolStripMenuItem1);
			this->menuToolStripMenuItem->DropDownItems->Add(testManagerToolStripMenuItem);
			this->testManagerToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUIClass::testManagerToolStripMenuItem_Click);
			this->visibilityToolStripMenuItem1->DropDownItems->Add(privateModeToolStripMenuItem1);
			this->privateModeToolStripMenuItem1->Click += gcnew System::EventHandler(this, &GUIClass::VisibilityChanged);
			this->visibilityToolStripMenuItem1->DropDownItems->Add(publicModeToolStripMenuItem);
			this->publicModeToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUIClass::VisibilityChanged);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 439);
			this->Text = L"Dashboard";
			this->SizeChanged += gcnew System::EventHandler(this, &GUIClass::Form1_SizeChanged);
			this->ResumeLayout(false);
			this->PerformLayout();
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;

			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);

			//DataGridView
			this->dataGridView1->Location = System::Drawing::Point(0, 96);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(this->Width - 12, this->Height - 130);
			this->dataGridView1->ColumnCount = 5+TestArray->GetUpperBound(0); // Column Counter
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->ColumnHeadersVisible = true;

			// 
			// textBox1- for search bar
			// 
			this->textBox1->Location = System::Drawing::Point(12, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(259, 20);
			this->textBox1->TabIndex = 2;
			this->Controls->Add(this->textBox1);
			this->textBox1->KeyUp += gcnew KeyEventHandler(this, &dash::GUIClass::pressedKey);
			
			


			//Set up timer for purging old data
			this->purgeAgeTimer->Tick += gcnew EventHandler(this, &GUIClass::TimerPurgeAgeProcessor);
			this->purgeAgeTimer->Interval = CHECK_PURGE_AGE_INTERVAL * 1000;
			this->purgeAgeTimer->Start();

			

			this->dataGridView1->Columns[0]->Name = "Name"; //public
			this->dataGridView1->Columns[1]->Name = "Name"; //private
			this->dataGridView1->Columns[1]->Visible = false;
			this->dataGridView1->Columns[2]->Name = "DOB";
			this->dataGridView1->Columns[3]->Name = "Arrival Time";
			this->dataGridView1->Columns[8]->Name = "Fetched";
			this->dataGridView1->Columns[8]->Visible = false;

			//adds however many tests we have in the tests array to the grid
			for (int i = 0; i < this->TestArray->GetUpperBound(0); i++){
				this->dataGridView1->Columns[i + 4]->Name = this->TestArray[i, 0]->ToString();
			}
		}
		/**
		This method is used by the listener method in dash to add rows to the grid.
		We take the array, add a fetched time to the end for the list limiting, and then
		add it to the grid.
		We then check the test dates and color in the test cells
		After that we resort if the table was already sorted
		Finally we check to see if we are above the max number of rows and delete older ones if so.
		Jason Fiduk and Craig Pennell
		*/
	public: System::Void addRow(array<String^> ^data)
	{
		array<Object^> ^objarray = gcnew array < Object^ >(data->Length + 1);
		System::Array::Copy(data, objarray, data->Length);
		time_t fetchTime;
		time(&fetchTime);
		objarray[data->Length] = fetchTime;
		dataGridView1->Rows->Add(objarray);
		checkTests(this->dataGridView1, dataGridView1->Rows->Count - 2);
		System::Text::RegularExpressions::Regex^ state = gcnew System::Text::RegularExpressions::Regex("\\b(" + textBox1->Text + ")([^ ]*)", System::Text::RegularExpressions::RegexOptions::IgnoreCase);
		if (!state->IsMatch(dataGridView1->Rows[dataGridView1->Rows->Count - 2]->Cells[1]->Value->ToString()))
				{
					this->dataGridView1->Rows[dataGridView1->Rows->Count - 2]->Visible = false;
				}
		if(dataGridView1->SortOrder == SortOrder::Ascending){
		dataGridView1->Sort(dataGridView1->SortedColumn, ListSortDirection::Ascending);
		}
		else if(dataGridView1->SortOrder == SortOrder::Descending){
			dataGridView1->Sort(dataGridView1->SortedColumn, ListSortDirection::Descending);
		}
		else{}
		if(!ListLimiterType){
		TimerPurgeSizeProcessor();
		}
		dataGridView1->PerformLayout();
	}

	/**
	Event that makes it so that the grid consistently takes up the same place in the window.
	Jason Fiduk
	*/
	private: System::Void Form1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridView1->Size = System::Drawing::Size(this->Width - 12, this->Height - 130);
	}
	/**
	Opens up the manager window when clicked.  After it is exited we manipluate the values of the list limiter in this class since they are pass
	by value, as comparted to the array and datagridview which is passed by reference.
	Jason Fiduk
	*/
	private: System::Void testManagerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Manager^ manager = gcnew Manager(this->dataGridView1, TestArray, ListLimiter, ListLimiterType);
		manager->FormClosed += gcnew FormClosedEventHandler(this, &dash::GUIClass::Form1_FormClosed);
		this->dataGridView1->Enabled = false;
		manager->ShowDialog(this);
		 if ( manager->DialogResult == System::Windows::Forms::DialogResult::OK )
		 {
			 this->ListLimiter = manager->ListLimiter;
			 this->ListLimiterType = manager->ListLimiterType;
			time_t newTime = (time_t) manager->ListLimiter;
			PURGE_AGE_INTERVAL =newTime * MINUTE_INTERVAL;
				PURGE_SIZE_MAX_ROWS= newTime;
				if(manager->ListLimiterType)
				{
				this->purgeAgeTimer->Tick += gcnew EventHandler(this, &GUIClass::TimerPurgeAgeProcessor);
				}
				else{
					this->purgeAgeTimer->Tick -= gcnew EventHandler(this, &GUIClass::TimerPurgeAgeProcessor);
					TimerPurgeSizeProcessor();
				}
		 }
	}
			 /**
			 checks all the tests after the form is closed just in case a test number was changed.
			 Jason Fiduk
			 */
			 void Form1_FormClosed(System::Object^ sender, FormClosedEventArgs^ e)
			 {
				 checkAll();
				 
				 
			 }
		/**
		Whenever a button is pressed in the search bar, we remove names that dont contain that/those character(s).
		Backspacing the search bar is the only way to return the grid back to normal.
		Jason Fiduk
		*/
	private:  void pressedKey(System::Object^  sender, KeyEventArgs^  e) {
		System::Text::RegularExpressions::Regex^ state = gcnew System::Text::RegularExpressions::Regex("\\b(" + textBox1->Text + ")([^ ]*)", System::Text::RegularExpressions::RegexOptions::IgnoreCase);
		for (int i = 0; i <= dataGridView1->Rows->Count - 2; i++){
			if (e->KeyCode == Keys::Back){
				if (state->IsMatch(dataGridView1->Rows[i]->Cells[1]->Value->ToString()))
				{
					this->dataGridView1->Rows[i]->Visible = true;
				}
			}
			else{
				if (!state->IsMatch(dataGridView1->Rows[i]->Cells[1]->Value->ToString()))
				{
					this->dataGridView1->Rows[i]->Visible = false;
				}
			}
		}
	}
			  /**
			  Activated when one of the visibility options is used in the menu.
			  Toggles a hidden name column with the visible one.
			  Jason Fiduk
			  */
	private: System::Void VisibilityChanged(System::Object^  sender, System::EventArgs^  e) {
		if (sender->Equals(this->privateModeToolStripMenuItem1)){
			this->publicModeToolStripMenuItem->Checked = false;
			this->privateModeToolStripMenuItem1->Checked = true;
			this->dataGridView1->Columns[0]->Visible = false;
			this->dataGridView1->Columns[1]->Visible = true;
		}
		else{
			this->privateModeToolStripMenuItem1->Checked = false;
			this->publicModeToolStripMenuItem->Checked = true;
			this->dataGridView1->Columns[0]->Visible = true;
			this->dataGridView1->Columns[1]->Visible = false;
		}
	}
			 //Seperate into seperate Time calculate file if possible.  Inside is all time math   -Jason Fiduk ***************************************

			 /**
			 calculates the date of a test done by tearing apart the string and making it into a date time.
			 returns null if it cant do it.
			 */
		  DateTime^ calculateDate(System::String^ s){
			  try{
		int month = Convert::ToInt32( s->Substring(4,2)); 
		int day = Convert::ToInt32(s->Substring(6,2));
		int year= Convert::ToInt32(s->Substring(0,4));
		return gcnew DateTime(year, month, day);
			  }
			  catch( Exception^ e){
				  return nullptr;
			  }

	}
		  /**
		  Loops through all the rows and checks the tests.
		  */
			 void checkAll(){
				 for (int i = 0; i <= dataGridView1->Rows->Count - 2; i++)
				 {
					 checkTests(dataGridView1, i);
				 }
			 }

			 /**
			 checks tests:
			 No string = red
			 String that is unreadable = red
			 if it gets past those we subtract the test date from the current date and compare to time span supplied by user.
			 if within range = green
			 outside range = yellow
			 */
			 void checkTests(DataGridView^ grid, int row_number)
			 {
				 //todays date
				 DateTime^ today = gcnew DateTime();
				 today = today->Today;
				 for (int i = 0; i < TestArray->GetUpperBound(0); i++)
				 {
					 System::Object^ dateValue = grid->Rows[row_number]->Cells[i + 4]->Value;
					 if (dateValue == "") //No test color red
					 {
						 grid->Rows[row_number]->Cells[i + 4]->Style->ForeColor = System::Drawing::Color::Red;
						 grid->Rows[row_number]->Cells[i + 4]->Style->BackColor = System::Drawing::Color::Red;
					 }
					 else{
						 DateTime^ date = calculateDate(dateValue->ToString());
						 if (date == nullptr)
						 {
							 grid->Rows[row_number]->Cells[i + 4]->Style->ForeColor = System::Drawing::Color::Red;
							 grid->Rows[row_number]->Cells[i + 4]->Style->BackColor = System::Drawing::Color::Red;
						 }
						 else{

							 TimeSpan^ s = today->Subtract(*date);
							 TimeSpan^ length = safe_cast<TimeSpan^>(this->TestArray[i, 1]);
							 if (length->CompareTo(s) == 1) //length is shorter than s.
							 {
								 grid->Rows[row_number]->Cells[i + 4]->Style->ForeColor = System::Drawing::Color::Green;
								 grid->Rows[row_number]->Cells[i + 4]->Style->BackColor = System::Drawing::Color::Green;
							 }

							 else{ //Exists but not in range.
								 grid->Rows[row_number]->Cells[i + 4]->Style->ForeColor = System::Drawing::Color::Yellow;
								 grid->Rows[row_number]->Cells[i + 4]->Style->BackColor = System::Drawing::Color::Yellow;
							 }
						 }
					 }
				 }
			 }
			 //******************************************************************************************************
	};
}
