#pragma once
#include "vector"
#include "cpuschalgo"
#include "string"
namespace CPUSchedulerSimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for simulator
	/// </summary>
	public ref class simulator : public System::Windows::Forms::Form
	{
	public:

		static int algocode = 0;

		System::String^ nameAlgo="";

		static std::vector<process>* table_in;

		/// output process table returned from fcfs
		static std::vector<process>* table_fcfs;
		

		/// output process table returned from sjf
		static std::vector<process>* table_sjf;

		/// output process table returned from srtf
		static std::vector<process>* table_srtf;

		/// output process table returned from rra
		static std::vector<process>* table_rra;

		/// gantt chart for fcfs
		static std::vector<int>* gc_fcfs;

		/// gantt chart for sjf
		static std::vector<int>* gc_sjf;

		/// gantt chart for srtf
		static std::vector<int>* gc_srtf;

		/// gantt chart for rra
		static std::vector<int>* gc_rra;

		static void pfcfs(){
			fcfs a1(*table_in);
			*table_fcfs = a1.perform_fcfs();
			*gc_fcfs = a1.get_gantt_chart();
			for (int i = 0; i < table_fcfs->size(); i++) {
				System::String^ d1 = "" + table_fcfs->at(i).get_ID();
				System::String^ d2 = "" + table_fcfs->at(i).get_AT();
				System::String^ d3 = "" + table_fcfs->at(i).get_BT();
				System::String^ d4 = "" + table_fcfs->at(i).get_CT();
				System::String^ d5 = "" + table_fcfs->at(i).get_RT();
				System::String^ d6 = "" + table_fcfs->at(i).get_WT();
				System::String^ d7 = "" + table_fcfs->at(i).get_TAT();
				opt->Rows->Add(d1, d2, d3,d4,d5,d6,d7);
			}
		}
	private: System::Windows::Forms::DataGridView^ opt;
	public:

	public:


	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ AT;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BT;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CT;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RT;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ WT;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TAT;

	public:	simulator()
		{
			table_fcfs = new std::vector<process>();
			gc_fcfs = new std::vector<int>();
			InitializeComponent();
			table_in = CPUSchedulerSimulator::createprocesstable::t;
		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~simulator()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ label1;
	protected:

	protected:

	protected:

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->opt = (gcnew System::Windows::Forms::DataGridView());
			this->PID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->WT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TAT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->opt))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(240, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Algorithm Simulator";
			// 
			// opt
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Ubuntu Mono", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->opt->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->opt->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->opt->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->PID, this->AT, this->BT,
					this->CT, this->RT, this->WT, this->TAT
			});
			this->opt->Location = System::Drawing::Point(17, 78);
			this->opt->Name = L"opt";
			this->opt->ReadOnly = true;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->opt->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->opt->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->opt->Size = System::Drawing::Size(392, 150);
			this->opt->TabIndex = 1;
			this->opt->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &simulator::dataGridView1_CellContentClick);
			// 
			// PID
			// 
			this->PID->HeaderText = L"PID";
			this->PID->Name = L"PID";
			this->PID->ReadOnly = true;
			this->PID->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->PID->Width = 50;
			// 
			// AT
			// 
			this->AT->HeaderText = L"AT";
			this->AT->Name = L"AT";
			this->AT->ReadOnly = true;
			this->AT->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->AT->Width = 50;
			// 
			// BT
			// 
			this->BT->HeaderText = L"BT";
			this->BT->Name = L"BT";
			this->BT->ReadOnly = true;
			this->BT->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->BT->Width = 50;
			// 
			// CT
			// 
			this->CT->HeaderText = L"CT";
			this->CT->Name = L"CT";
			this->CT->ReadOnly = true;
			this->CT->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->CT->Width = 50;
			// 
			// RT
			// 
			this->RT->HeaderText = L"RT";
			this->RT->Name = L"RT";
			this->RT->ReadOnly = true;
			this->RT->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->RT->Width = 50;
			// 
			// WT
			// 
			this->WT->HeaderText = L"WT";
			this->WT->Name = L"WT";
			this->WT->ReadOnly = true;
			this->WT->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->WT->Width = 50;
			// 
			// TAT
			// 
			this->TAT->HeaderText = L"TAT";
			this->TAT->Name = L"TAT";
			this->TAT->ReadOnly = true;
			this->TAT->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->TAT->Width = 50;
			// 
			// simulator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(428, 554);
			this->Controls->Add(this->opt);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Ubuntu Mono", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"simulator";
			this->Text = L"simulator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->opt))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
};
}
