/*
*This is the prototype class that contains what the whole main dashboard is going to look like.
*In the end the grid will be its own C++ class that will be manipulated by helper classes and an object of it will be displayed 
*in a class for the main dashboard.  Each component is explained with comments when its initialized what it will do in the 
*final version.
*/
#pragma once

namespace dash {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected: 
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  visibilityToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  privateModeToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  publicModeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testManagerToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  sortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripComboBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  dateOfBirthToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  arrivalTimeToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DoB;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Arrival;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  catScan;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ERVisit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Hospitalization;











	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DoB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Arrival = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->catScan = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ERVisit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Hospitalization = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->visibilityToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->privateModeToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->publicModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testManagerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dateOfBirthToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->arrivalTimeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->menuToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(844, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->visibilityToolStripMenuItem1, 
				this->testManagerToolStripMenuItem, this->sortToolStripMenuItem});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// visibilityToolStripMenuItem1
			//Will contain the ability to make the app public or private.
			// 
			this->visibilityToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->privateModeToolStripMenuItem1, 
				this->publicModeToolStripMenuItem});
			this->visibilityToolStripMenuItem1->Name = L"visibilityToolStripMenuItem1";
			this->visibilityToolStripMenuItem1->Size = System::Drawing::Size(146, 22);
			this->visibilityToolStripMenuItem1->Text = L"Visibility";
			// 
			// privateModeToolStripMenuItem1
			//Will leave the names in tact since nobody but doctors will be able to see them.
			// 
			this->privateModeToolStripMenuItem1->Name = L"privateModeToolStripMenuItem1";
			this->privateModeToolStripMenuItem1->Size = System::Drawing::Size(144, 22);
			this->privateModeToolStripMenuItem1->Text = L"Private mode";
			// 
			// publicModeToolStripMenuItem
			//Will star out part of the names in the grid so that the app can be used in a public setting.
			// 
			this->publicModeToolStripMenuItem->Name = L"publicModeToolStripMenuItem";
			this->publicModeToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->publicModeToolStripMenuItem->Text = L"Public mode";
			// 
			// testManagerToolStripMenuItem
			//Will bring up a seperate window which will allow doctors to change which tests and date ranges they want.
			// 
			this->testManagerToolStripMenuItem->Name = L"testManagerToolStripMenuItem";
			this->testManagerToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->testManagerToolStripMenuItem->Text = L"Test Manager";
			this->testManagerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testManagerToolStripMenuItem_Click);
			// 
			// sortToolStripMenuItem
			//Used so doctors can sort the list any way they want.
			// 
			this->sortToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripComboBox1, 
				this->dateOfBirthToolStripMenuItem, this->arrivalTimeToolStripMenuItem});
			this->sortToolStripMenuItem->Name = L"sortToolStripMenuItem";
			this->sortToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->sortToolStripMenuItem->Text = L"Sort";
			// 
			// toolStripComboBox1-title of field in
			//Allows you to sort the grid by last name.
			// 
			this->toolStripComboBox1->Name = L"toolStripComboBox1";
			this->toolStripComboBox1->Size = System::Drawing::Size(140, 22);
			this->toolStripComboBox1->Text = L"Last name";
			// 
			// dateOfBirthToolStripMenuItem
			//Allows you to sort the grid by Date of Birth.
			// 
			this->dateOfBirthToolStripMenuItem->Name = L"dateOfBirthToolStripMenuItem";
			this->dateOfBirthToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->dateOfBirthToolStripMenuItem->Text = L"Date of Birth";
			// 
			// arrivalTimeToolStripMenuItem
			//Allows you to sort the grid by patient arrival time.
			// 
			this->arrivalTimeToolStripMenuItem->Name = L"arrivalTimeToolStripMenuItem";
			this->arrivalTimeToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->arrivalTimeToolStripMenuItem->Text = L"Arrival time";
			// 
			// textBox1
			//Will take input and allow doctors to limit their list based on putting in part or a whole last name.
			// 
			this->textBox1->Location = System::Drawing::Point(12, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(259, 20);
			this->textBox1->TabIndex = 2;
			// 
			// Form1
			//The main container for the dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 439);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Text = L"Dashboard";
			this->SizeChanged += gcnew System::EventHandler(this, &Form1::Form1_SizeChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
			// 
			// dataGridView1
			//The grid that will display all the information and be manipulated. Will be its own class in final product.
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->Name, this->DoB, 
				this->Arrival, this->catScan, this->ERVisit, this->Hospitalization});
			this->dataGridView1->Location = System::Drawing::Point(0, 96);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(this->Width, this->Height-96);
			this->dataGridView1->TabIndex = 0;
			// 
			// Name -table column header identifier
			// 
			this->Name->HeaderText = L"Name";
			this->Name->Name = L"Name";
			// 
			// DoB-table column header identifier
			// 
			this->DoB->HeaderText = L"Date of Birth";
			this->DoB->Name = L"DoB";
			// 
			// Arrival-table column header identifier
			// 
			this->Arrival->HeaderText = L"Arrival Time";
			this->Arrival->Name = L"Arrival";
			// 
			// catScan-table column header test
			// 
			this->catScan->HeaderText = L"CAT Scan";
			this->catScan->Name = L"catScan";
			// 
			// ERVisit-table column header test 
			// 
			this->ERVisit->HeaderText = L"ER Visit";
			this->ERVisit->Name = L"ERVisit";
			// 
			// Hospitalization-table column header test
			// 
			this->Hospitalization->HeaderText = L"Hospitalization";
			this->Hospitalization->Name = L"Hospitalization";

		}
#pragma endregionc
//Displays the Manager.h window when the Manager tool button is clicked in the options.
private: System::Void testManagerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Manager^ test = gcnew Manager();
		test->Show();
		 }
		// Scales the grid when the window size is changed.
private: System::Void Form1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->dataGridView1->Size = System::Drawing::Size(this->Width, this->Height-96);
		 }
};
}

