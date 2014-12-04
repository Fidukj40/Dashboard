
#include "Manager.h"
/**
This form is used to allow the user to customize their dashboard.  It allows the user to show/hide tests,
change the date range that the tests can be in,
and change how the list is limited in size (minutes or # of people)
Jason Fiduk
*/
namespace Manage {

	
		

		/**
		Constructor that sets all parameters to global values so they can be used than initializes the form.
		*/
		 Manager::Manager( DataGridView^ other,array<Object^,2>^ TestArray,  int ListLimiter, bool ListLimiterType ){
			 dashGrid = other;
			 this->ListLimiter = ListLimiter;
			 this->ListLimiterType = ListLimiterType;
			 this->TestArray = TestArray;
			 InitializeComponent();
		 }

			  
	/**
	Initializes the form
	Goes through the test array and populates it that way.
	In the future have the size of the screen increase for tests added, or convert to list that can be editted.
	The ok button and list limiter options are made here too.
	Jason Fiduk
	*/
		void Manager::InitializeComponent(void)
		{
			//Loops throught the tests and displays options for them
			for(int i=0; i < this->TestArray->GetUpperBound(0); i++)
			{
				System::Windows::Forms::CheckBox^  checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				System::Windows::Forms::ComboBox^ comboBox1 = (gcnew System::Windows::Forms::ComboBox());
				System::Windows::Forms::Label^ label1 = (gcnew System::Windows::Forms::Label());
			System::Windows::Forms::TextBox^  textBox1= (gcnew System::Windows::Forms::TextBox());

		    checkBox1->AutoSize = true;
			if(dashGrid->Columns[i+4]->Visible){
			checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			}
			checkBox1->Location = System::Drawing::Point(12, (i*80) +1);
			checkBox1->Name = L"checkBox1";
			checkBox1->Size = System::Drawing::Size(70, 17);
			checkBox1->TabIndex = 0;
			checkBox1->Text = TestArray[i,0]->ToString();
			checkBox1->UseVisualStyleBackColor = true;
			checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Manager::comboBoxUncheck);

			
			textBox1->Location = System::Drawing::Point(150, (i*80)+1);
			textBox1->Name = TestArray[i,0]->ToString();
			if(!dashGrid->Columns[i+4]->Visible){
				textBox1->Enabled = false;
			}
			textBox1->Size = System::Drawing::Size(56, 21);
			textBox1->TabIndex = 4;
			textBox1->Text = ((safe_cast <TimeSpan^>(TestArray[i,1]))->Days).ToString();

			label1->AutoSize = true;
			label1->Location = System::Drawing::Point(210, (i*80)+1);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(35, 13);
			label1->TabIndex = 0;
			label1->Text = L"Days";

			this->Controls->Add(checkBox1); //evens
			this->Controls->Add(textBox1); //odds
			this->Controls->Add(label1);

			}

			//radio buttions for list limiters
			this->radio1 =gcnew System::Windows::Forms::RadioButton();
			this->radio2 = gcnew System::Windows::Forms::RadioButton();
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->LimitingNumber= (gcnew System::Windows::Forms::TextBox());
			
			this->radio1->Location = System::Drawing::Point(171, 290);
			this->radio2->Location = System::Drawing::Point(171, 315);
			this->radio1->Text = "Minutes";
			this->radio2->Text = "# of people";

			//textbox for adding a number for the size/time limit
			this->LimitingNumber->Location = System::Drawing::Point(110, 303);
			this->LimitingNumber->Size = System::Drawing::Size(45, 21);
			this->LimitingNumber->Text = System::Convert::ToString(ListLimiter);
			if(ListLimiterType){
				radio1->Checked = true;
			}
			else{
				radio2->Checked = true;
			}
			//
			// button1
			// 
			this->button1->Location = System::Drawing::Point(171, 350);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"OK";
			this-> button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Manager::button1_Click);
			
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radio1);
			this->Controls->Add(this->radio2);
			this->Controls->Add(this->LimitingNumber);
			this->AcceptButton = button1;
			// 
			// Manager
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(398, 400);
			
			
		}
#pragma endregion
		/**
		Called when a checkBox is unchecked or checked.  It makes it so the date range for that test cant be editted if the test
		is turned off or allows you if its turned on.
		Jason  Fiduk
		*/
			  System::Void Manager::comboBoxUncheck(System::Object^  sender, System::EventArgs^  e) {
						  CheckBox^ clone = safe_cast<CheckBox^>(sender);
						  array<Control^>^ options = this->Controls->Find(clone->Text,true);
						 if(!clone->Checked)
						{
							options[0]->Enabled = false;
						}
						 else{
							 options[0]->Enabled= true;
						 }
					  }
					  /**
					  Called when the ok button is hit.
					  It shows/hides columns based on the checkboxes.
					  It updates the tests arrays date times
					  It updates the list limiter variables to used when the thread returns to the manager function that made this form.
					  Jason Fiduk
					  */
 System::Void Manager::button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 for( int i = 0, v=0; i< this->Controls->Count-4;i+=3,v++)
			 {
				 if(safe_cast<CheckBox^>(this->Controls[i])->Checked)
				 {
					 dashGrid->Columns[v+4]->Visible = true;
				 }
				 else{
						dashGrid->Columns[v+4]->Visible = false;
				 }
				 try{
				 this->TestArray[v,1]= TimeSpan(Convert::ToInt32(safe_cast<TextBox^>(this->Controls[i+1])->Text,10),0,0,0);
				 }
				 catch(FormatException^ e){
					 this->TestArray[v,1]= TimeSpan(7,0,0,0);
				 }
			 }
			 
				 ListLimiterType = radio1->Checked;
			  ListLimiter =int::Parse(LimitingNumber->Text);
			dashGrid->Enabled = true;
			Manager::Close();
}

}
