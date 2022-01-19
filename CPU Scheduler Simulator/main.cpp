#include "MyForm.h"
#include "iostream"
#include "climode.h"


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
    climode::start();
/*
    int mode;
    std::cout << "Enter 0 to continue with CLI Mode\nEnter 1 to continue with GUI Mode"<<std::endl;
    std::cout << "Input Goes Here => ";
    std::cin >> mode;
    mode ? GUI() : CLI();
    */
}

