#include "MyForm.h"
#include "iostream"
#include "cpuschalgo.h"


using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void GUI(void) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    CPUSchedulerSimulator::MyForm form;
    Application::Run(% form);
}

void CLI(void) {
    std::cout << "CLI MODE STARTED" << std::endl;
}

void main(array<System::String^>^ args)
{

    //process p1(1, 0, 11, 0), p2(2, 0, 8, 0), p3(3, 12, 2, 0), p4(4, 2, 6, 0), p5(5, 9, 16, 0);
    process p1(1,0, 5,0), p2(2,1, 6,0), p3(3,2, 3,0), p4(4,3, 3,0), p5(5,4, 5,0),p6(6,6,4,0);
    
    std::vector<process> p;
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);
    p.push_back(p6);
    std::vector<int> gc;
   
    
    fcfs f(p);
    f.perform_fcfs();
    gc = f.get_gantt_chart();
    print_gantt_chart(gc);
    print_stats(f);
    
    std::cout << std::endl;

    sjf sj(p);
    sj.perform_sjf();
    gc = sj.get_gantt_chart();
    print_gantt_chart(gc);
    print_stats(sj);
    
    srtf sr(p);
    sr.perform_srtf();
    gc = sr.get_gantt_chart();
    print_gantt_chart(gc);
    print_stats(sr);
   
    roundrobin r(p,4);
    r.perform_roundrobin();
    gc = r.get_gantt_chart();
    print_gantt_chart(gc);
    print_stats(r);

    /*
    int mode;
    std::cout << "Enter 0 to continue with CLI Mode\nEnter 1 to continue with GUI Mode"<<std::endl;
    std::cout << "Input Goes Here => ";
    std::cin >> mode;
    mode ? GUI() : CLI();
    */
}

