#pragma once
#include "vector"
#include "cpuschalgo"
#include "string"
#include "algorithm"
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
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Label^ label3;
	public: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::DataGridView^ gc;
	public: System::Windows::Forms::DataGridView^ opt;
	public: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ avgrt;
	private: System::Windows::Forms::TextBox^ avgwt;
	private: System::Windows::Forms::TextBox^ avgtat;
	private: System::Windows::Forms::Label^ tql;

	

	public:

	public:

		/// gantt chart for rra
		static std::vector<int>* gc_rra;

		void pfcfs(){
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
			
			for (int i = 0; i < gc_fcfs->size() + 1; i++) {
				System::String^ d1 = "" + i;
				gc->Columns->Add(d1,d1);
			}
			gc->Rows->Add();
			
			for (int i = 0; i < gc_fcfs->size(); i++) {
				if (gc_fcfs->at(i) != -1) {
					gc->Rows[0]->Cells[i]->Value = "P" + gc_fcfs->at(i)+"  ";
				}
				else {
					gc->Rows[0]->Cells[i]->Value = "Idle ";
				}
				
			}
			avgrt->Text = a1.get_avg_rt().ToString();
			avgwt->Text = a1.get_avg_wt().ToString();
			avgtat->Text = a1.get_avg_tat().ToString();
		}

		void psjf() {
			sjf a2(*table_in);
			*table_sjf = a2.perform_sjf();
			*gc_sjf = a2.get_gantt_chart();
			for (int i = 0; i < table_sjf->size(); i++) {
				System::String^ d1 = "" + table_sjf->at(i).get_ID();
				System::String^ d2 = "" + table_sjf->at(i).get_AT();
				System::String^ d3 = "" + table_sjf->at(i).get_BT();
				System::String^ d4 = "" + table_sjf->at(i).get_CT();
				System::String^ d5 = "" + table_sjf->at(i).get_RT();
				System::String^ d6 = "" + table_sjf->at(i).get_WT();
				System::String^ d7 = "" + table_sjf->at(i).get_TAT();
				opt->Rows->Add(d1, d2, d3, d4, d5, d6, d7);
			}

			for (int i = 0; i < gc_sjf->size() + 1; i++) {
				System::String^ d1 = "" + i;
				gc->Columns->Add(d1, d1);
			}
			gc->Rows->Add();

			for (int i = 0; i < gc_sjf->size(); i++) {
				if (gc_sjf->at(i) != -1) {
					gc->Rows[0]->Cells[i]->Value = "P" + gc_sjf->at(i) + "  ";
				}
				else {
					gc->Rows[0]->Cells[i]->Value = "Idle ";
				}

			}
			avgrt->Text = a2.get_avg_rt().ToString();
			avgwt->Text = a2.get_avg_wt().ToString();
			avgtat->Text = a2.get_avg_tat().ToString();
		}

		void psrtf() {
			srtf a3(*table_in);
			*table_srtf = a3.perform_srtf();
			*gc_srtf = a3.get_gantt_chart();
			for (int i = 0; i < table_srtf->size(); i++) {
				System::String^ d1 = "" + table_srtf->at(i).get_ID();
				System::String^ d2 = "" + table_srtf->at(i).get_AT();
				System::String^ d3 = "" + table_srtf->at(i).get_BT();
				System::String^ d4 = "" + table_srtf->at(i).get_CT();
				System::String^ d5 = "" + table_srtf->at(i).get_RT();
				System::String^ d6 = "" + table_srtf->at(i).get_WT();
				System::String^ d7 = "" + table_srtf->at(i).get_TAT();
				opt->Rows->Add(d1, d2, d3, d4, d5, d6, d7);
			}

			for (int i = 0; i < gc_srtf->size() + 1; i++) {
				System::String^ d1 = "" + i;
				gc->Columns->Add(d1, d1);
			}
			gc->Rows->Add();

			for (int i = 0; i < gc_srtf->size(); i++) {
				if (gc_srtf->at(i) != -1) {
					gc->Rows[0]->Cells[i]->Value = "P" + gc_srtf->at(i) + "  ";
				}
				else {
					gc->Rows[0]->Cells[i]->Value = "Idle ";
				}

			}
			avgrt->Text = a3.get_avg_rt().ToString();
			avgwt->Text = a3.get_avg_wt().ToString();
			avgtat->Text = a3.get_avg_tat().ToString();
		}

		void prra(int tq) {
			roundrobin a4(*table_in,tq);
			*table_rra = a4.perform_roundrobin();
			*gc_rra = a4.get_gantt_chart();
			for (int i = 0; i < table_rra->size(); i++) {
				System::String^ d1 = "" + table_rra->at(i).get_ID();
				System::String^ d2 = "" + table_rra->at(i).get_AT();
				System::String^ d3 = "" + table_rra->at(i).get_BT();
				System::String^ d4 = "" + table_rra->at(i).get_CT();
				System::String^ d5 = "" + table_rra->at(i).get_RT();
				System::String^ d6 = "" + table_rra->at(i).get_WT();
				System::String^ d7 = "" + table_rra->at(i).get_TAT();
				opt->Rows->Add(d1, d2, d3, d4, d5, d6, d7);
			}

			for (int i = 0; i < gc_rra->size() + 1; i++) {
				System::String^ d1 = "" + i;
				gc->Columns->Add(d1, d1);
			}
			gc->Rows->Add();

			for (int i = 0; i < gc_rra->size(); i++) {
				if (gc_rra->at(i) != -1) {
					gc->Rows[0]->Cells[i]->Value = "P" + gc_rra->at(i) + "  ";
				}
				else {
					gc->Rows[0]->Cells[i]->Value = "Idle ";
				}

			}
			avgrt->Text = a4.get_avg_rt().ToString();
			avgwt->Text = a4.get_avg_wt().ToString();
			avgtat->Text = a4.get_avg_tat().ToString();
		}

		void sTQL(int tq) {
			String^ m = "Time Quantum : " + tq;
			tql->Text = m;
			tql->Visible = true;
		}
		void hTQL() {
			tql->Visible = false;
		}

	

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
			table_sjf = new std::vector<process>();
			gc_sjf = new std::vector<int>();
			table_srtf = new std::vector<process>();
			gc_srtf = new std::vector<int>();
			table_rra = new std::vector<process>();
			gc_rra = new std::vector<int>();
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
protected:

protected:

	protected:

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(simulator::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->opt = (gcnew System::Windows::Forms::DataGridView());
			this->PID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->WT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TAT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->gc = (gcnew System::Windows::Forms::DataGridView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->avgrt = (gcnew System::Windows::Forms::TextBox());
			this->avgwt = (gcnew System::Windows::Forms::TextBox());
			this->avgtat = (gcnew System::Windows::Forms::TextBox());
			this->tql = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->opt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gc))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(258, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(240, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Algorithm Simulator";
			// 
			// opt
			// 
			this->opt->AllowUserToAddRows = false;
			this->opt->AllowUserToDeleteRows = false;
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
			this->opt->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->opt->Location = System::Drawing::Point(15, 105);
			this->opt->MultiSelect = false;
			this->opt->Name = L"opt";
			this->opt->ReadOnly = true;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->opt->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->opt->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->opt->Size = System::Drawing::Size(392, 153);
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(240, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Algorithm Simulator";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(156, 25);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Result Table";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 284);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(144, 25);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Gantt Chart";
			// 
			// gc
			// 
			this->gc->AllowUserToAddRows = false;
			this->gc->AllowUserToDeleteRows = false;
			this->gc->AllowUserToResizeColumns = false;
			this->gc->AllowUserToResizeRows = false;
			this->gc->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->gc->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->gc->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->gc->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gc->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->gc->Location = System::Drawing::Point(17, 312);
			this->gc->MultiSelect = false;
			this->gc->Name = L"gc";
			this->gc->ReadOnly = true;
			this->gc->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleRight;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Ubuntu Mono", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->gc->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleRight;
			this->gc->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->gc->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->gc->Size = System::Drawing::Size(784, 72);
			this->gc->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(435, 89);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(168, 25);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Statistics : ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(435, 135);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(156, 25);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Average RT :";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(435, 184);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(156, 25);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Average WT :";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(435, 230);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(168, 25);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Average TAT :";
			// 
			// avgrt
			// 
			this->avgrt->Enabled = false;
			this->avgrt->Location = System::Drawing::Point(608, 132);
			this->avgrt->Name = L"avgrt";
			this->avgrt->Size = System::Drawing::Size(193, 31);
			this->avgrt->TabIndex = 10;
			// 
			// avgwt
			// 
			this->avgwt->Enabled = false;
			this->avgwt->Location = System::Drawing::Point(608, 179);
			this->avgwt->Name = L"avgwt";
			this->avgwt->Size = System::Drawing::Size(193, 31);
			this->avgwt->TabIndex = 11;
			// 
			// avgtat
			// 
			this->avgtat->Enabled = false;
			this->avgtat->Location = System::Drawing::Point(608, 227);
			this->avgtat->Name = L"avgtat";
			this->avgtat->Size = System::Drawing::Size(193, 31);
			this->avgtat->TabIndex = 12;
			// 
			// tql
			// 
			this->tql->AutoSize = true;
			this->tql->Location = System::Drawing::Point(578, 284);
			this->tql->Name = L"tql";
			this->tql->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tql->Size = System::Drawing::Size(180, 25);
			this->tql->TabIndex = 13;
			this->tql->Text = L"Time Quantum :";
			this->tql->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->tql->Visible = false;
			// 
			// simulator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(826, 398);
			this->Controls->Add(this->tql);
			this->Controls->Add(this->avgtat);
			this->Controls->Add(this->avgwt);
			this->Controls->Add(this->avgrt);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->gc);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->opt);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Ubuntu Mono", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"simulator";
			this->Text = L"simulator";
			this->Load += gcnew System::EventHandler(this, &simulator::simulator_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->opt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gc))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void simulator_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
