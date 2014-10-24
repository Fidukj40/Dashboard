#include "Manager.cpp"
namespace dash {
using namespace System;	
using namespace Manage;
using namespace System::Windows::Forms;
using namespace System::Drawing;
public ref class GUIClass : public System::Windows::Forms::Form
{
	private: System::Windows::Forms::DataGridView^  dataGridView1;
private: static array<bool>^ options = gcnew array<bool>(3)
	{ true, true, false};
private: System::Windows::Forms::MenuStrip^ menuStrip1;
private:  System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
		  private: System::Windows::Forms::ToolStripMenuItem^  visibilityToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  privateModeToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  publicModeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testManagerToolStripMenuItem;
			
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
		this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
		this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->visibilityToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
					this->privateModeToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
						this->publicModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
							this->testManagerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());

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
			this->dataGridView1->Size = System::Drawing::Size(this->Width, this->Height-96);
			 this->dataGridView1->ColumnCount = 7;
			 this->dataGridView1->ReadOnly=true;
      this->dataGridView1->ColumnHeadersVisible = true;

	     this->dataGridView1->Columns[ 0 ]->Name = "Name"; //public
		 this->dataGridView1->Columns[ 1 ]->Name = "Name"; //private
		 this->dataGridView1->Columns[ 1 ]->Visible=false;
      this->dataGridView1->Columns[ 2 ]->Name = "DOB";
      this->dataGridView1->Columns[ 3 ]->Name = "Arrival Time";
      this->dataGridView1->Columns[ 4 ]->Name = "Test1";
	    this->dataGridView1->Columns[ 5 ]->Name = "Test2";
		  this->dataGridView1->Columns[ 6 ]->Name = "Test3";
			//this->dataGridView1->TabIndex = 0;
			
			array<String^>^row1 = gcnew array<String^>{
         "Fid**,Ja***","Fiduk, Jason","08-21-93","???", "true","true","true"
      };
		dataGridView1->Rows->Add(row1  );
	}
public:
	void show(){
		Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
		Application::Run(this);
	}
	private: System::Void Form1_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->dataGridView1->Size = System::Drawing::Size(this->Width, this->Height-96);
		 }
			 private: System::Void testManagerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Manager^ test = gcnew Manager(this->dataGridView1, options);
		test->Show();
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
};
}
