#include"gui"
#include "iostream"
#include "climode"


using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void GUI(void) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    CPUSchedulerSimulator::gui f;
    Application::Run(% f);
}

void CLI(void) {
    climode::start();
}

void main(array<System::String^>^ args)
{   
    int mode;
    std::cout << "Enter 0 to continue with CLI Mode\nEnter 1 to continue with GUI Mode"<<std::endl;
    std::cout << "Input Goes Here => ";
    std::cin >> mode;
    mode ? GUI() : CLI();
}

