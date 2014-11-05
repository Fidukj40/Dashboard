#pragma once
#include <iostream>
namespace Manage {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;


	//array<string>^ Tests = gcnew array<string>(3){"Cat Scan","ER Visit", "Hospitalization"};
	/// <summary>
	/// Summary for Manager
	/// </summary>
	public ref class Manager : public System::Windows::Forms::Form
	{
		private: System::Windows::Forms::DataGridView^  dashGrid;
				 private: static array<bool>^ options;
						   private: static array<TimeSpan>^ lengths;

	public:
		Manager(void)
		{
			InitializeComponent();
		}

	public:
		 Manager( DataGridView^ other, array<bool>^ options, array<TimeSpan>^ lengths  ){
			 dashGrid = other;
			 this->options = options;
			 this->lengths = lengths;
			 InitializeComponent();
		 }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Manager()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
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
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			if(options[0]){
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			}
			this->checkBox1->Location = System::Drawing::Point(12, 1);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(70, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Cat Scan";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Manager::comboBoxUncheck);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			if(options[1]){
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			}
			this->checkBox2->Location = System::Drawing::Point(12, 84);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(41, 17);
			this->checkBox2->TabIndex = 1;
			this->checkBox2->Text = L"ER Visit";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Manager::comboBoxUncheck);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			if(options[2]){
			this->checkBox3->CheckState = System::Windows::Forms::CheckState::Checked;
			}
			this->checkBox3->Location = System::Drawing::Point(12, 160);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(56, 17);
			this->checkBox3->TabIndex = 2;
			this->checkBox3->Text = L"Hospitalization";	
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Manager::comboBoxUncheck);
			
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^>(31) {L"0",L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", 
				L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26", 
				L"27", L"28", L"29", L"30"});
			this->comboBox1->SelectedItem = (lengths[0].Days % 7).ToString();
			this->comboBox1->Location = System::Drawing::Point(171, 36);
			this->comboBox1->Name = L"Cat Scan";
			this->comboBox1->Size = System::Drawing::Size(56, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->Text = L"Days";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Manager::comboBox1_SelectedIndexChanged);
			this->comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(31) {L"0",L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", 
				L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26", 
				L"27", L"28", L"29", L"30"});
			this->comboBox2->Location = System::Drawing::Point(171, 112);
			this->comboBox2->Name = L"ER Visit";
			this->comboBox2->SelectedItem = (lengths[1].Days % 7).ToString();
			this->comboBox2->Size = System::Drawing::Size(56, 21);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->Text = L"Days";
				this->comboBox2->DropDownStyle = ComboBoxStyle::DropDownList;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(31) {L"0",L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", 
				L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26", 
				L"27", L"28", L"29", L"30"});
			this->comboBox3->Location = System::Drawing::Point(171, 188);
			this->comboBox3->Name = L"Hospitalization";
			this->comboBox3->SelectedItem = (lengths[2].Days % 7).ToString();
			this->comboBox3->Size = System::Drawing::Size(56, 21);
			this->comboBox3->TabIndex = 5;
			this->comboBox3->Text = L"Days";
				this->comboBox3->DropDownStyle = ComboBoxStyle::DropDownList;
			//
			// button1
			// 
			this->button1->Location = System::Drawing::Point(171, 227);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Manager::button1_Click);
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(13) {L"0",L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", 
				L"9", L"10", L"11", L"12"});
			this->comboBox4->Location = System::Drawing::Point(21, 188);
			this->comboBox4->Name = L"Hospitalization";
			this->comboBox4->Size = System::Drawing::Size(56, 21);
			this->comboBox4->TabIndex = 7;
			this->comboBox4->SelectedItem = (lengths[2].Days / 7).ToString();
			this->comboBox4->Text = L"Weeks";
				this->comboBox4->DropDownStyle = ComboBoxStyle::DropDownList;
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(13) {L"0",L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", 
				L"9", L"10", L"11", L"12"});
			this->comboBox5->Location = System::Drawing::Point(21, 36);
			this->comboBox5->Name = L"Cat Scan";
			this->comboBox5->Size = System::Drawing::Size(56, 21);
			this->comboBox5->TabIndex = 8;
			this->comboBox5->SelectedItem = (lengths[0].Days / 7).ToString();
			this->comboBox5->Text = L"Weeks";
				this->comboBox5->DropDownStyle = ComboBoxStyle::DropDownList;
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(13) {L"0",L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", 
				L"9", L"10", L"11", L"12"});
			this->comboBox6->Location = System::Drawing::Point(21, 112);
			this->comboBox6->Name = L"ER Visit";
			this->comboBox6->Size = System::Drawing::Size(56, 21);
			this->comboBox6->TabIndex = 9;
			this->comboBox6->SelectedItem = (lengths[1].Days / 7).ToString();
			this->comboBox6->Text = L"Weeks";
				this->comboBox6->DropDownStyle = ComboBoxStyle::DropDownList;
					// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(80, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Weeks";
				// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(80, 112);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Weeks";
				// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(80, 188);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Weeks";
					// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(239, 36);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Days";
				// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(239, 112);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Days";
				// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(239, 188);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Days";
			// 
			// Manager
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(398, 262);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Name = L"Manager";
			this->Text = L"Manager";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
			 private: System::Void comboBoxUncheck(System::Object^  sender, System::EventArgs^  e) {
						  CheckBox^ clone = safe_cast<CheckBox^>(sender);
						  array<Control^>^ options = this->Controls->Find(clone->Text,true);
						 if(!clone->Checked)
						{
							options[0]->Enabled = false;
							options[1]->Enabled = false;
						}
						 else{
							 options[0]->Enabled= true;
							options[1]->Enabled = true;
						 }
					  }

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			
		    if(checkBox1->Checked)
			{
			dashGrid->Columns[4]->Visible = true;
			this->options[0] = true;
			}
			else{
				dashGrid->Columns[4]->Visible = false;
				this->options[0] = false;
			}
			if(checkBox2->Checked)
			{
			dashGrid->Columns[5]->Visible = true;
			this->options[1] = true;
			}
			else{
			dashGrid->Columns[5]->Visible = false;
			this->options[1] = false;
			}
			if(checkBox3->Checked)
			{
			dashGrid->Columns[6]->Visible = true;
			this->options[2] = true;
			}
			else{
			dashGrid->Columns[6]->Visible = false;
			this->options[2] = false;
			}
			Console::WriteLine(comboBox1->Text);
			this->lengths[0]= TimeSpan(Convert::ToInt32(comboBox1->Text,10) + (Convert::ToInt32(comboBox5->Text,10) * 7),0,0,0);
			this->lengths[1]= TimeSpan(Convert::ToInt32(comboBox2->Text,10) + (Convert::ToInt32(comboBox6->Text,10) * 7),0,0,0);
			this->lengths[2]=TimeSpan(Convert::ToInt32(comboBox3->Text,10) + (Convert::ToInt32(comboBox4->Text,10) * 7),0,0,0);
			dashGrid->Enabled = true;
			Manager::Close();
}

};
}
