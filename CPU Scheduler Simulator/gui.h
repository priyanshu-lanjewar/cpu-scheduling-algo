#pragma once
#ifndef _GUI_
#define _GUI_
#ifndef _CREATEPROCESSTABLE_
#include "createprocesstable.h"
//#include "createprocesstable.h"
#endif // !_CREATEPROCESSTABLE_
#include "simulator.h"
#include "stdlib.h"
#using <Microsoft.VisualBasic.dll>
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
			}		private: System::Windows::Forms::Label^ title;
		//private: System::Windows::Forms::TextBox^ msg;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Button^ creaept;

		private: System::Windows::Forms::Button^ simulate;


		private: System::Windows::Forms::Button^ button2;
		private: System::Windows::Forms::Button^ button3;
		private: System::Windows::Forms::ComboBox^ algo;
		private: System::Windows::Forms::StatusStrip^ statusStrip1;
		private: System::Windows::Forms::ToolStripStatusLabel^ msg;


		private: System::Windows::Forms::ToolStripMenuItem^ testToolStripMenuItem1;
		private: System::Windows::Forms::ToolStripMenuItem^ testToolStripMenuItem;
		private: System::Windows::Forms::Button^ button1;


		private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;


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
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->creaept = (gcnew System::Windows::Forms::Button());
				this->simulate = (gcnew System::Windows::Forms::Button());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->button3 = (gcnew System::Windows::Forms::Button());
				this->algo = (gcnew System::Windows::Forms::ComboBox());
				this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
				this->msg = (gcnew System::Windows::Forms::ToolStripStatusLabel());
				this->testToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->statusStrip1->SuspendLayout();
				this->SuspendLayout();
				// 
				// title
				// 
				this->title->AutoSize = true;
				this->title->Location = System::Drawing::Point(7, 17);
				this->title->Name = L"title";
				this->title->Size = System::Drawing::Size(420, 25);
				this->title->TabIndex = 1;
				this->title->Text = L"CPU SCHEDULING ALGORITHM SIMULATOR";
				this->title->Click += gcnew System::EventHandler(this, &gui::label1_Click);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(12, 62);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(192, 25);
				this->label1->TabIndex = 3;
				this->label1->Text = L"Process Table :";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(9, 160);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(276, 25);
				this->label2->TabIndex = 4;
				this->label2->Text = L"Scheduling Algorithm :";
				// 
				// creaept
				// 
				this->creaept->Location = System::Drawing::Point(12, 102);
				this->creaept->Name = L"creaept";
				this->creaept->Size = System::Drawing::Size(155, 38);
				this->creaept->TabIndex = 5;
				this->creaept->Text = L"Create";
				this->creaept->UseVisualStyleBackColor = true;
				this->creaept->Click += gcnew System::EventHandler(this, &gui::creaept_Click);
				// 
				// simulate
				// 
				this->simulate->Location = System::Drawing::Point(124, 254);
				this->simulate->Name = L"simulate";
				this->simulate->Size = System::Drawing::Size(294, 40);
				this->simulate->TabIndex = 8;
				this->simulate->Text = L"Simulate Algorithm";
				this->simulate->UseVisualStyleBackColor = true;
				this->simulate->Click += gcnew System::EventHandler(this, &gui::simulate_Click);
				// 
				// button2
				// 
				this->button2->Location = System::Drawing::Point(196, 102);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(155, 38);
				this->button2->TabIndex = 9;
				this->button2->Text = L"Edit";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->Click += gcnew System::EventHandler(this, &gui::button2_Click);
				// 
				// button3
				// 
				this->button3->Location = System::Drawing::Point(379, 102);
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
				this->algo->Location = System::Drawing::Point(12, 197);
				this->algo->Name = L"algo";
				this->algo->Size = System::Drawing::Size(522, 33);
				this->algo->TabIndex = 11;
				// 
				// statusStrip1
				// 
				this->statusStrip1->Font = (gcnew System::Drawing::Font(L"Ubuntu Mono", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->msg });
				this->statusStrip1->Location = System::Drawing::Point(0, 323);
				this->statusStrip1->Name = L"statusStrip1";
				this->statusStrip1->Size = System::Drawing::Size(546, 25);
				this->statusStrip1->TabIndex = 12;
				this->statusStrip1->Text = L"statusStrip1";
				// 
				// msg
				// 
				this->msg->Name = L"msg";
				this->msg->Size = System::Drawing::Size(378, 20);
				this->msg->Text = L"Errors/Warnings/Status will be shown here";
				// 
				// testToolStripMenuItem1
				// 
				this->testToolStripMenuItem1->Name = L"testToolStripMenuItem1";
				this->testToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
				this->testToolStripMenuItem1->Text = L"test";
				// 
				// testToolStripMenuItem
				// 
				this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
				this->testToolStripMenuItem->Size = System::Drawing::Size(180, 22);
				this->testToolStripMenuItem->Text = L"test";
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(453, 12);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(81, 34);
				this->button1->TabIndex = 13;
				this->button1->Text = L"About";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &gui::button1_Click_1);
				// 
				// gui
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
				this->BackColor = System::Drawing::SystemColors::AppWorkspace;
				this->ClientSize = System::Drawing::Size(546, 348);
				this->Controls->Add(this->button1);
				this->Controls->Add(this->statusStrip1);
				this->Controls->Add(this->algo);
				this->Controls->Add(this->button3);
				this->Controls->Add(this->button2);
				this->Controls->Add(this->simulate);
				this->Controls->Add(this->creaept);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->title);
				this->Font = (gcnew System::Drawing::Font(L"Ubuntu Mono", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
				this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				this->Name = L"gui";
				this->Text = L"CPU SCHEDULING ALGORITHM SIMULATOR";
				this->statusStrip1->ResumeLayout(false);
				this->statusStrip1->PerformLayout();
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
					msg->Text = "Executing First Come First Serve";
					CPUSchedulerSimulator::simulator s;
					s.label1->Text = "First Come First Serve";
					s.pfcfs();
					s.ShowDialog();
					msg->Text = "First Come First Serve Execution Completed";
				}
				else if (algo->Text == "Shortest Job First") {
					msg->Text = "Executing Shortest Job First";
					CPUSchedulerSimulator::simulator s;
					s.label1->Text = "Shortest Job First";
					s.psjf();
					s.ShowDialog();
					msg->Text = "Shortest Job First Execution Completed";
				}
				else if (algo->Text == "Shortest Remaining Time First") {
					msg->Text = "Executing Shortest Remaining Time First";
					CPUSchedulerSimulator::simulator s;
					s.label1->Text = "Shortest Remaining Time First";
					s.psrtf();
					s.ShowDialog();
					msg->Text = "Shortest Remaining Time First Execution Completed";
				}
				else if (algo->Text == "Round Robin Algorithm") {
					msg->Text = "Executing Round Robin Algorithm";
					System::String^ tq = Microsoft::VisualBasic::Interaction::InputBox("Enter Time Quantum Here\nDefault Value is 1", "Round Robin Time Quantum Input","1", 100, 100);
					int i_tq = System::Convert::ToUInt32(tq);
					CPUSchedulerSimulator::simulator s;
					s.label1->Text = "Round Robin Algorithm";
					s.prra(i_tq);
					s.sTQL(i_tq);
					s.ShowDialog();
					s.hTQL();
					msg->Text = "Round Robin Algorithm Execution Completed";
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
			CPUSchedulerSimulator::createprocesstable c;
			CPUSchedulerSimulator::createprocesstable::t->clear();
			c.initTable();
			c.ShowDialog();
			ptCreated = CPUSchedulerSimulator::createprocesstable::tableCreated;
			if (ptCreated) {
				msg->Text = "Process Table Created Successfully.";
			}
			else {
				msg->Text = "No Process Table Created";
			}
		}
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			CPUSchedulerSimulator::createprocesstable c;
			c.disableBtn();
			c.ShowDialog();
			c.enableBtn();
		}
private: System::Void statusStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void toolStripStatusLabel1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	CPUSchedulerSimulator::createprocesstable c;
	c.ShowDialog();
	ptCreated = CPUSchedulerSimulator::createprocesstable::tableCreated;
	if (ptCreated) {
		msg->Text = "Process Table Created Successfully.";
	}
	else {
		msg->Text = "No Process Table Created";
	}
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {

	Microsoft::VisualBasic::Interaction::MsgBox("This Application is developed by Priyanshu Lanjewar, as an End Term Project for 3rd Year.", Microsoft::VisualBasic::MsgBoxStyle::Information, "About Developer");
}
};
}
#endif // !_GUI_
