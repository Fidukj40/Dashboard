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
	public ref class Manager : public System::Windows::Forms::Form
	{
		public:  
		bool ListLimiterType;
		int ListLimiter;
		private: 
		System::Windows::Forms::DataGridView^  dashGrid;
		array<Object^,2>^ TestArray;
		 System::Windows::Forms::CheckBox^  checkBox1;
	 System::Windows::Forms::Button^  button1;
	 System::Windows::Forms::Label^  label1;
	 System::Windows::Forms::RadioButton^ radio1;
	 System::Windows::Forms::RadioButton^ radio2;
	 System::Windows::Forms::TextBox^  LimitingNumber;
		public:
			Manager( DataGridView^ other,array<Object^,2>^ TestArray,  int ListLimiter, bool ListLimiterType );
	private: 
		void InitializeComponent(void);
		void button1_Click(System::Object^  sender, System::EventArgs^  e);
		void comboBoxUncheck(System::Object^  sender, System::EventArgs^  e);
	};
}
