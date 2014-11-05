#include "Manager.cpp"
//#include "TimeComparer.cpp"
namespace dash {
using namespace System;	
using namespace Manage;
using namespace System::Windows::Forms;
using namespace System::Drawing;
public ref class GUIClass : public System::Windows::Forms::Form
{
	private: System::Windows::Forms::DataGridView^  dataGridView1;
private: static array<bool>^ options = gcnew array<bool>(3)
	{ true, true, true};

private: static array<TimeSpan>^ timeRange = gcnew array<TimeSpan>(3){ TimeSpan(7,0,0,0), TimeSpan(7,0,0,0), TimeSpan(31,0,0,0)};
		 
private: System::Windows::Forms::MenuStrip^ menuStrip1;
private:  System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
		  private: System::Windows::Forms::ToolStripMenuItem^  visibilityToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  privateModeToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  publicModeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testManagerToolStripMenuItem;
			 private: System::Windows::Forms::TextBox^  textBox1;
			
public:
	
	public:
		 GUIClass( GUIClass^ other){
			 init();
		 }

	GUIClass(){
		init();
		
	}
private:
	void init(){
		Console::WriteLine(timeRange[0].ToString());
		this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
		this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->visibilityToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
					this->privateModeToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
						this->publicModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
							this->testManagerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
								this->textBox1 = (gcnew System::Windows::Forms::TextBox());

			this->menuToolStripMenuItem->Text = L"Menu";
			this->visibilityToolStripMenuItem1->Text = L"Visibility";
			this->privateModeToolStripMenuItem1->Text = L"Private Mode";
			this->publicModeToolStripMenuItem->Text = L"Public Mode";

			this->publicModeToolStripMenuItem->Checked= true;

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

			this->dataGridView1->Location = System::Drawing::Point(0, 96);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible= false;
			this->dataGridView1->Size = System::Drawing::Size(this->Width-12, this->Height-130);
			 this->dataGridView1->ColumnCount = 7;
			 this->dataGridView1->ReadOnly=true;
      this->dataGridView1->ColumnHeadersVisible = true;

	  // 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(259, 20);
			this->textBox1->TabIndex = 2;
			this->Controls->Add(this->textBox1);
			this->textBox1->KeyUp += gcnew KeyEventHandler(this, &dash::GUIClass::pressedKey);

	     this->dataGridView1->Columns[ 0 ]->Name = "Name"; //public
		 this->dataGridView1->Columns[ 1 ]->Name = "Name"; //private
		 this->dataGridView1->Columns[ 1 ]->Visible=false;
      this->dataGridView1->Columns[ 2 ]->Name = "DOB";
      this->dataGridView1->Columns[ 3 ]->Name = "Arrival Time";
      this->dataGridView1->Columns[ 4 ]->Name = "Cat Scan";
	    this->dataGridView1->Columns[ 5 ]->Name = "ER Visit";
		  this->dataGridView1->Columns[ 6 ]->Name = "Hospitalization";
			//this->dataGridView1->TabIndex = 0;
	
 //ADD TEST ROWS************************
			array<String^>^row1 = gcnew array<String^>{
         "Fid**,Ja***","Fiduk, Jason","19930821","20140805", "09/20/2014","10/29/2014",""
      };
		dataGridView1->Rows->Add(row1);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();

		array<String^>^rowA = gcnew array<String^>{
"Pen**,Cra***", "Pennell, Craig", "19891225", "20140203", "10/23/2014", "09/21/2013", ""
};
		dataGridView1->Rows->Add(rowA);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();
array<String^>^rowB = gcnew array<String^>{
"Sch***,Joe", "Schmoe, Joe", "19551011", "20141012", "", "10/21/2014", "10/20/2014"
};
dataGridView1->Rows->Add(rowB);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();
array<String^>^rowC = gcnew array<String^>{
"Mon***,Bur***", "Montgomery, Burns", "18060606", "20140923", "10/20/1989", "", "02/01/1900"
};
dataGridView1->Rows->Add(rowC);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();
array<String^>^rowD = gcnew array<String^>{
"Fuc***, You***", "Fuchs,Youra", "19990612", "20140830", "10/20/2014", "", ""
};
dataGridView1->Rows->Add(rowD);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();
array<String^>^rowE = gcnew array<String^>{
"Cla***, Jer***", "Clarion, Jerry", "19730418", "20100917", "09/20/2014", "", ""
};
dataGridView1->Rows->Add(rowE);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();

		array<String^>^rowF = gcnew array<String^>{
"McP***, Gil***", "McPherrson, Gilbert", "19991102", "20110313", "", "02/28/2013", "10/01/2014"
};
dataGridView1->Rows->Add(rowF);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();

array<String^>^rowG = gcnew array<String^>{
"Til***, Sho***", "Tiller, Shonda", "19820714", "20070413", "", "06/30/2013", ""
};
dataGridView1->Rows->Add(rowG);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();

array<String^>^rowH = gcnew array<String^>{
"O'D***, Mic***", "O'Donald, Micheal", "19560313", "20130701", "", "", "08/21/2014"
};
dataGridView1->Rows->Add(rowH);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();

array<String^>^rowI = gcnew array<String^>{
"Por***, Sus***", "Porter, Susan", "19671208", "20140412", "01/31/2000", "02/01/2000", "08/21/2014"
};
dataGridView1->Rows->Add(rowI);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();

array<String^>^rowJ = gcnew array<String^>{
"Hun***, Wil***", "Huntington, Willard", "19540627", "20131010", "09/30/2012", "", ""
};
dataGridView1->Rows->Add(rowI);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();

array<String^>^rowK = gcnew array<String^>{
"DeM***, Bea***", "DeMarco, Beatrice", "19950122", "20140530", "09/30/2012", "", "08/20/2014"
};
dataGridView1->Rows->Add(rowK);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();

array<String^>^rowL = gcnew array<String^>{
"Lem***, Ran***", "Lemire, Randolf", "19780401", "20090822", "", "06/12/2010", ""
};
dataGridView1->Rows->Add(rowL);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();

array<String^>^rowM = gcnew array<String^>{
"Gre***, Dar***", "Greenfield, Dareen", "19850229", "20101216", "", "", "10/10/2010"
};
dataGridView1->Rows->Add(rowM);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();

		array<String^>^rowN = gcnew array<String^>{
"Dra***, Han***", "Drake, Hannah", "19970915", "20110615", "", "", ""
};
dataGridView1->Rows->Add(rowN);
		checkTests(this->dataGridView1,dataGridView1->Rows->Count-2);
		dataGridView1->PerformLayout();
			
//***************************************************
	}
public:
	
	private: System::Void Form1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->dataGridView1->Size = System::Drawing::Size(this->Width-12, this->Height-130);
		 }

	private: System::Void testManagerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Manager^ test = gcnew Manager(this->dataGridView1, options,timeRange);
		test->FormClosed += gcnew FormClosedEventHandler(this,&dash::GUIClass::Form1_FormClosed);
		this->dataGridView1->Enabled=false;
		test->ShowDialog();
		 }
	void Form1_FormClosed(System::Object^ sender, FormClosedEventArgs^ e)
    {
        checkAll();
    }
	private:  void pressedKey(System::Object^  sender, KeyEventArgs^  e) {
				  System::Text::RegularExpressions::Regex^ state= gcnew System::Text::RegularExpressions::Regex("\\b("+ textBox1->Text +")([^ ]*)", System::Text::RegularExpressions::RegexOptions::IgnoreCase); 
				  for(int i = 0; i<=dataGridView1->Rows->Count-2;i++){
				  if(e->KeyCode == Keys::Back){
					   if(state->IsMatch(dataGridView1->Rows[i]->Cells[1]->Value->ToString()))
					  {
						   this->dataGridView1->Rows[ i ]->Visible=true;
					  }
				  }
				  else{
					  Console::WriteLine(textBox1->Text);
					  if(!state->IsMatch(dataGridView1->Rows[i]->Cells[1]->Value->ToString()))
					  {
						   this->dataGridView1->Rows[ i ]->Visible=false;
					  }
					 // Console::WriteLine("Test");
				  }
				  }
			  }
private: System::Void VisibilityChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(sender->Equals(this->privateModeToolStripMenuItem1)){
				 this->publicModeToolStripMenuItem->Checked = false;
				 this->privateModeToolStripMenuItem1->Checked = true;
				 this->dataGridView1->Columns[ 0 ]->Visible=false;
				 this->dataGridView1->Columns[ 1 ]->Visible=true;
			 }
			 else{
				 this->privateModeToolStripMenuItem1->Checked = false;
				 this->publicModeToolStripMenuItem->Checked = true;
				 this->dataGridView1->Columns[ 0 ]->Visible=true;
				 this->dataGridView1->Columns[ 1 ]->Visible=false;
			 }
		 }
//Seperate into seperate Time calculate file if possible ***************************************
		  DateTime^ calculateDate(System::String^ s){
		int month = Convert::ToInt32( s->Substring(0,2)); 
		int day = Convert::ToInt32(s->Substring(3,2));
		int year= Convert::ToInt32(s->Substring(6,4));
		return gcnew DateTime(year, month, day);

	}
		  void checkAll(){
			  for(int i=0;i<=dataGridView1->Rows->Count-2;i++)
			  {
				  checkTests(dataGridView1, i);
			  }
		  }
//add rows using datagridview add method
//pass grid reference, get latest row, check tests
 void checkTests(DataGridView^ grid, int row_number )
{
	//todays date
	DateTime^ today = gcnew DateTime();
	today= today->Today;
	for(int i=0; i<3;i++)
	{
		System::Object^ dateValue = grid->Rows[row_number]->Cells[i+4]->Value;
		if(dateValue=="")
		{
	grid->Rows[row_number]->Cells[i+4]->Style->ForeColor = System::Drawing::Color::Red;
	grid->Rows[row_number]->Cells[i+4]->Style->BackColor = System::Drawing::Color::Red;
		}
		else{
	DateTime^ date = calculateDate(dateValue->ToString());
	TimeSpan^ s  = today->Subtract(*date);
	TimeSpan^ length = timeRange[i];
	
	 if(length->CompareTo(s) == 1) //length is shorter than s.
	{
	//Console::WriteLine("green");
	grid->Rows[row_number]->Cells[i+4]->Style->ForeColor = System::Drawing::Color::Green;
	grid->Rows[row_number]->Cells[i+4]->Style->BackColor = System::Drawing::Color::Green;
	}
	
	else{ //Exists but not in range.
//Console::WriteLine("yellow");
grid->Rows[row_number]->Cells[i+4]->Style->ForeColor = System::Drawing::Color::Yellow;
grid->Rows[row_number]->Cells[i+4]->Style->BackColor = System::Drawing::Color::Yellow;
	}
		}
	}
}
 //******************************************************************************************************
};
}
