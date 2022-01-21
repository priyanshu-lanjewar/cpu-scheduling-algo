#pragma once
#ifndef _GUI_
#define _GUI_
#ifndef _CREATEPROCESSTABLE_
#include "createprocesstable.h"
//#include "createprocesstable.h"
#endif // !_CREATEPROCESSTABLE_
#include "simulator.h"
#include "stdlib.h"
namespace CPUSchedulerSimulator {
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;

		/// <summary>
		/// Summary for gui
		/// </summary>
		public ref class gui : public System::Windows::Forms::Form
		{
		private:

		public:

			static bool ptCreated;
			gui(void)
			{
				ptCreated = false;
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~gui()
			{
				if (components)
				{
					delete components;
				}
			}

		private: System::Windows::Forms::Label^ title;
		private: System::Windows::Forms::TextBox^ msg;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Button^ creaept;

		private: System::Windows::Forms::Button^ simulate;


		private: System::Windows::Forms::Button^ button2;
		private: System::Windows::Forms::Button^ button3;
		private: System::Windows::Forms::ComboBox^ algo;

		protected:

		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(gui::typeid));
				this->title = (gcnew System::Windows::Forms::Label());
				this->msg = (gcnew System::Windows::Forms::TextBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->creaept = (gcnew System::Windows::Forms::Button());
				this->simulate = (gcnew System::Windows::Forms::Button());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->button3 = (gcnew System::Windows::Forms::Button());
				this->algo = (gcnew System::Windows::Forms::ComboBox());
				this->SuspendLayout();
				// 
				// title
				// 
				this->title->AutoSize = true;
				this->title->Location = System::Drawing::Point(63, 42);
				this->title->Name = L"title";
				this->title->Size = System::Drawing::Size(420, 25);
				this->title->TabIndex = 1;
				this->title->Text = L"CPU SCHEDULING ALGORITHM SIMULATOR";
				this->title->Click += gcnew System::EventHandler(this, &gui::label1_Click);
				// 
				// msg
				// 
				this->msg->Enabled = false;
				this->msg->ForeColor = System::Drawing::Color::Red;
				this->msg->Location = System::Drawing::Point(12, 350);
				this->msg->Name = L"msg";
				this->msg->ReadOnly = true;
				this->msg->Size = System::Drawing::Size(522, 31);
				this->msg->TabIndex = 2;
				this->msg->Text = L"Errors / Warnings Will Be Displayed Here";
				this->msg->UseWaitCursor = true;
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(28, 92);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(192, 25);
				this->label1->TabIndex = 3;
				this->label1->Text = L"Process Table :";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(28, 190);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(276, 25);
				this->label2->TabIndex = 4;
				this->label2->Text = L"Scheduling Algorithm :";
				// 
				// creaept
				// 
				this->creaept->Location = System::Drawing::Point(12, 132);
				this->creaept->Name = L"creaept";
				this->creaept->Size = System::Drawing::Size(155, 38);
				this->creaept->TabIndex = 5;
				this->creaept->Text = L"Create";
				this->creaept->UseVisualStyleBackColor = true;
				this->creaept->Click += gcnew System::EventHandler(this, &gui::creaept_Click);
				// 
				// simulate
				// 
				this->simulate->Location = System::Drawing::Point(124, 284);
				this->simulate->Name = L"simulate";
				this->simulate->Size = System::Drawing::Size(294, 40);
				this->simulate->TabIndex = 8;
				this->simulate->Text = L"Simulate Algorithm";
				this->simulate->UseVisualStyleBackColor = true;
				this->simulate->Click += gcnew System::EventHandler(this, &gui::simulate_Click);
				// 
				// button2
				// 
				this->button2->Location = System::Drawing::Point(196, 132);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(155, 38);
				this->button2->TabIndex = 9;
				this->button2->Text = L"Edit";
				this->button2->UseVisualStyleBackColor = true;
				// 
				// button3
				// 
				this->button3->Location = System::Drawing::Point(379, 132);
				this->button3->Name = L"button3";
				this->button3->Size = System::Drawing::Size(155, 38);
				this->button3->TabIndex = 10;
				this->button3->Text = L"View";
				this->button3->UseVisualStyleBackColor = true;
				this->button3->Click += gcnew System::EventHandler(this, &gui::button3_Click);
				// 
				// algo
				// 
				this->algo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				this->algo->FormattingEnabled = true;
				this->algo->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
					L"First Come First Serve", L"Shortest Job First", L"Shortest Remaining Time First",
						L"Round Robin Algorithm"
				});
				this->algo->Location = System::Drawing::Point(12, 227);
				this->algo->Name = L"algo";
				this->algo->Size = System::Drawing::Size(522, 33);
				this->algo->TabIndex = 11;
				// 
				// gui
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
				this->BackColor = System::Drawing::SystemColors::AppWorkspace;
				this->ClientSize = System::Drawing::Size(546, 393);
				this->Controls->Add(this->algo);
				this->Controls->Add(this->button3);
				this->Controls->Add(this->button2);
				this->Controls->Add(this->simulate);
				this->Controls->Add(this->creaept);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->msg);
				this->Controls->Add(this->title);
				this->Font = (gcnew System::Drawing::Font(L"Ubuntu Mono", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
				this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				this->Name = L"gui";
				this->Text = L"CPU SCHEDULING ALGORITHM SIMULATOR";
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			system("1");
			//_exit(0);
		}
		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void simulate_Click(System::Object^ sender, System::EventArgs^ e) {
			if (ptCreated) {
				if (algo->Text == "First Come First Serve") {
					std::string g = "g";
					CPUSchedulerSimulator::simulator s;
					CPUSchedulerSimulator::simulator::label1->Text = "First Come First Serve CPU Scheduling Algorithm";
					CPUSchedulerSimulator::simulator::pfcfs();
					s.ShowDialog();
				}
				else if (algo->Text == "Shortest Job First") {
					msg->Text = "sjf";
				}
				else if (algo->Text == "Shortest Remaining Time First") {
					msg->Text = "srtf";
				}
				else if (algo->Text == "Round Robin Algorithm") {
					msg->Text = "rra";
				}
				else {
					msg->Text = "Please Select A Valid Algorithm";
				}
			}
			else
			{
				msg->Text = "No Process Table Found";
			}
		}
		private: System::Void creaept_Click(System::Object^ sender, System::EventArgs^ e) {
			ptCreated = false;
			//CPUSchedulerSimulator::createprocesstable::t->clear();
			CPUSchedulerSimulator::createprocesstable c;
			c.ShowDialog();
			ptCreated = CPUSchedulerSimulator::createprocesstable::tableCreated;
			msg->Text = ptCreated.ToString();
		}
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			CPUSchedulerSimulator::createprocesstable c;
			c.ShowDialog();
		}
};
}
#endif // !_GUI_
