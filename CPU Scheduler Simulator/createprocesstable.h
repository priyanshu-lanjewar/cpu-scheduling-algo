#pragma once
#ifndef  _CREATEPROCESSTABLE_
#define  _CREATEPROCESSTABLE_

#include "gui.h"
//#endif
#include "cpuschalgo"
#include "vector"
namespace CPUSchedulerSimulator {
	
		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace System::Collections::Generic;
		using namespace System::ComponentModel;


		/// <summary>
		/// Summary for createprocesstable
		/// </summary>
		public ref class createprocesstable : public System::Windows::Forms::Form
		{
		private:

		public:
			static std::vector<process>* t = new std::vector<process>();;
		private: System::Windows::Forms::DataGridView^ tb;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ PID;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ AT;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ BT;



		public:



			   static bool tableCreated = false;
		public:	createprocesstable(void)
			{
				//t = 
				InitializeComponent();

				for (int i = 0; i < t->size(); i++) {
					System::String^ d1 = "" + t->at(i).get_ID();
					System::String^ d2 = "" + t->at(i).get_AT();
					System::String^ d3 = "" + t->at(i).get_BT();
					tb->Rows->Add(d1, d2, d3);
				}
				
				
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~createprocesstable()
			{
				if (components)
				{
					delete components;
				}
			}

		protected:

		protected:





		private: System::Windows::Forms::Button^ add;
		private: System::Windows::Forms::TextBox^ at_t;
		private: System::Windows::Forms::TextBox^ bt_t;

			   

		private: System::Windows::Forms::TextBox^ pid_t;
		private: System::Windows::Forms::Button^ save;
		private: System::Windows::Forms::Button^ clear;




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
				this->add = (gcnew System::Windows::Forms::Button());
				this->pid_t = (gcnew System::Windows::Forms::TextBox());
				this->at_t = (gcnew System::Windows::Forms::TextBox());
				this->bt_t = (gcnew System::Windows::Forms::TextBox());
				this->save = (gcnew System::Windows::Forms::Button());
				this->clear = (gcnew System::Windows::Forms::Button());
				this->tb = (gcnew System::Windows::Forms::DataGridView());
				this->PID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->AT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->BT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb))->BeginInit();
				this->SuspendLayout();
				// 
				// add
				// 
				this->add->Location = System::Drawing::Point(186, 291);
				this->add->Name = L"add";
				this->add->Size = System::Drawing::Size(75, 23);
				this->add->TabIndex = 3;
				this->add->Text = L"Add";
				this->add->UseVisualStyleBackColor = true;
				this->add->Click += gcnew System::EventHandler(this, &createprocesstable::c_Click);
				// 
				// pid_t
				// 
				this->pid_t->Font = (gcnew System::Drawing::Font(L"Ubuntu Mono", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->pid_t->Location = System::Drawing::Point(12, 254);
				this->pid_t->Name = L"pid_t";
				this->pid_t->Size = System::Drawing::Size(71, 31);
				this->pid_t->TabIndex = 4;
				// 
				// at_t
				// 
				this->at_t->Font = (gcnew System::Drawing::Font(L"Ubuntu Mono", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->at_t->Location = System::Drawing::Point(98, 254);
				this->at_t->Name = L"at_t";
				this->at_t->Size = System::Drawing::Size(71, 31);
				this->at_t->TabIndex = 5;
				// 
				// bt_t
				// 
				this->bt_t->Font = (gcnew System::Drawing::Font(L"Ubuntu Mono", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->bt_t->Location = System::Drawing::Point(190, 254);
				this->bt_t->Name = L"bt_t";
				this->bt_t->Size = System::Drawing::Size(71, 31);
				this->bt_t->TabIndex = 6;
				// 
				// save
				// 
				this->save->Location = System::Drawing::Point(94, 291);
				this->save->Name = L"save";
				this->save->Size = System::Drawing::Size(75, 23);
				this->save->TabIndex = 7;
				this->save->Text = L"Save";
				this->save->UseVisualStyleBackColor = true;
				this->save->Click += gcnew System::EventHandler(this, &createprocesstable::save_Click);
				// 
				// clear
				// 
				this->clear->Location = System::Drawing::Point(12, 291);
				this->clear->Name = L"clear";
				this->clear->Size = System::Drawing::Size(75, 23);
				this->clear->TabIndex = 8;
				this->clear->Text = L"Clear";
				this->clear->UseVisualStyleBackColor = true;
				this->clear->Click += gcnew System::EventHandler(this, &createprocesstable::clear_Click);
				// 
				// tb
				// 
				this->tb->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->tb->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) { this->PID, this->AT, this->BT });
				this->tb->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
				this->tb->Location = System::Drawing::Point(13, 12);
				this->tb->Name = L"tb";
				this->tb->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
				this->tb->Size = System::Drawing::Size(248, 236);
				this->tb->TabIndex = 10;
				// 
				// PID
				// 
				this->PID->HeaderText = L"PID";
				this->PID->Name = L"PID";
				this->PID->ReadOnly = true;
				this->PID->Resizable = System::Windows::Forms::DataGridViewTriState::False;
				this->PID->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
				this->PID->Width = 70;
				// 
				// AT
				// 
				this->AT->HeaderText = L"AT";
				this->AT->Name = L"AT";
				this->AT->ReadOnly = true;
				this->AT->Resizable = System::Windows::Forms::DataGridViewTriState::False;
				this->AT->Width = 70;
				// 
				// BT
				// 
				this->BT->FillWeight = 50;
				this->BT->HeaderText = L"BT";
				this->BT->Name = L"BT";
				this->BT->ReadOnly = true;
				this->BT->Resizable = System::Windows::Forms::DataGridViewTriState::False;
				this->BT->Width = 70;
				// 
				// createprocesstable
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(284, 336);
				this->Controls->Add(this->tb);
				this->Controls->Add(this->clear);
				this->Controls->Add(this->save);
				this->Controls->Add(this->bt_t);
				this->Controls->Add(this->at_t);
				this->Controls->Add(this->pid_t);
				this->Controls->Add(this->add);
				this->Name = L"createprocesstable";
				this->Text = L"Create Process Table";
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}



		private: System::Void c_Click(System::Object^ sender, System::EventArgs^ e) {
			if (pid_t->Text == "" ||
				at_t->Text == "" ||
				bt_t->Text == "") {

			}
			else {
				tableCreated = true;
				int pid = 0;
				int at = 0;
				int bt = 0;
				pid = Convert::ToInt32(pid_t->Text);
				at = Convert::ToInt32(at_t->Text);
				bt = Convert::ToInt32(bt_t->Text);
				t->push_back(process(pid, at, bt));
				System::String^ d1 = "" + pid_t->Text;
				System::String^ d2 = "" + at_t->Text;
				System::String^ d3 = "" + bt_t->Text;
				tb->Rows->Add(d1, d2, d3);
				pid_t->Text = "";
				at_t->Text = "";
				bt_t->Text = "";
			}
		}
		private: System::Void clear_Click(System::Object^ sender, System::EventArgs^ e) {
			t->clear();
			tb->Rows->Clear();
			tableCreated = false;;
		}
		private: System::Void save_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		};
}
#endif // ! _CREATEPROCESSTABLE_