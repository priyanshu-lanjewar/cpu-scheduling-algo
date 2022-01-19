#pragma once
#ifndef _PROCESS_
#define _PROCESS_
#ifndef _CSTDARG_
#include "cstdarg"
#endif
#ifndef _VECTOR_
#include "vector"
#endif
class process
{
private:
	/// <summary>
	/// Private Attribute of Process:
	/// </summary>
	
	/// ID : Just for Identification
	int ID;

	/// AT : Arrival Time
	int AT;

	/// BT : Burst Time
	int BT;

	/// PR : Priority
	int PR;

	/// CT : Completion Time
	int CT;

	/// WT : Waiting Time
	int WT;

	/// RT : Response Time
	int RT;

	/// NT : Need Time ( Is defined here just for convinience )
	int NT;

	/// TAT : Turn Around Time
	int TAT;
	

public:
	/// Public Members of process class
	/// <summary>
	/// Constructor for process
	/// </summary>
	/// <param name="AT">: Time of Arrival of Process</param>
	/// <param name="BT">: Execution time of Process</param>
	/// <param name="PR">: Priority of a Process</param>
	process(int ID,int AT, int BT, int PR);

	/// <summary>
	/// Function to initialize process variable already Declared with AT=BT=PR=0
	/// </summary>
	/// <param name="AT">: Time of Arrival of Process</param>
	/// <param name="BT">: Execution time of Process</param>
	/// <param name="PR">: Priority of a Process</param>
	void create(int ID, int AT, int BT, int PR=0);

	/// <summary>
	/// Setter Function For Completion Time
	/// </summary>
	/// <param name="CT">Completion Time</param>
	void set_CT(int CT);

	/// <summary>
	/// Setter Function for Waiting Time
	/// </summary>
	void calculate_WT();

	/// <summary>
	/// Setter Function for Response Time
	/// </summary>
	/// <param name="RT">Response Time</param>
	void set_RT(int RT);

	/// <summary>
	/// Setter Function for Need Time
	/// </summary>
	/// <param name="NT">Need Time</param>
	void set_NT(int NT);

	/// <summary>
	/// Calculating Function for Turn Around Time
	/// </summary>
	void calculate_TAT();

	int get_ID();

	/// <summary>
	/// Getter Function for Arrival Time
	/// </summary>
	/// <returns>AT : Time of Arrival of Process</returns>
	int get_AT();

	/// <summary>
	/// Getter Function for Burst Time
	/// </summary>
	/// <returns>BT : Burst/Execution Time of Process</returns>
	int get_BT();

	/// <summary>
	/// Getter Function for Priority
	/// </summary>
	/// <returns>PR : Priority of Process</returns>
	int get_PR();

	/// <summary>
	/// Getter Function for Completion Time
	/// </summary>
	/// <returns>CT : Completion Time of Process</returns>
	int get_CT();

	/// <summary>
	/// Getter Function for Waiting Time
	/// </summary>
	/// <returns>WT : Waiting Time of Process</returns>
	int get_WT();

	/// <summary>
	/// Getter Function for Response Time
	/// </summary>
	/// <returns>RT : Response Time of Process</returns>
	int get_RT();

	/// <summary>
	/// Getter Function for Need Time
	/// </summary>
	/// <returns>NT : Need Time of Process</returns>
	int get_NT();

	/// <summary>
	/// Getter Function for Turn Around Time
	/// </summary>
	/// <returns>TAT : Turn Around Time of a Process</returns>
	int get_TAT();

	/// <summary>
	/// Function to Calculate Average Waiting Time
	/// </summary>
	/// <param name="process_count">: Number Of Process</param>
	/// <param name="">processes : process1, process2, process3....</param>
	/// <returns>Average Waiting Time of inputed process</returns>
	friend double average_WT(int process_count, ...);

	/// <summary>
	/// Function to Calculate Average Response Time
	/// </summary>
	/// <param name="process_count">: Number Of Process</param>
	/// <param name="">processes : process1, process2, process3....</param>
	/// <returns>Average Response Time of inputed process</returns>
	friend double average_RT(int process_count, ...);

	/// <summary>
	/// Function to Calculate Average Turn Around Time
	/// </summary>
	/// <param name="process_count">: Number Of Process</param>
	/// <param name="">processes : process1, process2, process3....</param>
	/// <returns>Average Turn Around Time of inputed process</returns>
	friend double average_TAT(int process_count, ...);
	
	/// <summary>
	/// Function to Calculate Average Waiting Time
	/// </summary>
	/// <param name="process_count">: Number Of Process</param>
	/// <param name="p">: Vector of Process</param>
	/// <returns>Average Waiting Time of inputed process</returns>
	friend double average_WT(std::vector<process> p);

	/// <summary>
	/// Function to Calculate Average Response Time
	/// </summary>
	/// <param name="process_count">: Number Of Process</param>
	/// <param name="p">: Vector of Process</param>
	/// <returns>Average Response Time of inputed process</returns>
	friend double average_RT(std::vector<process> p);

	/// <summary>
	/// Function to Calculate Average Turn Around Time
	/// </summary>
	/// <param name="process_count">: Number Of Process</param>
	/// <param name="p">: Vector of Process</param>
	/// <returns>Average Turn Around Time of inputed process</returns>
	friend double average_TAT(std::vector<process> p);
};


/// Defination of all the member function declared above

process::process(int ID=0,int AT = 0, int BT = 0, int PR = 0) {
	this->ID = ID;
	this->AT = AT;
	this->BT = BT;
	this->PR = PR;
	this->NT = BT;
}

void process::create(int ID, int AT, int BT, int PR) {
	this->ID = ID;
	this->AT = AT;
	this->BT = BT;
	this->PR = PR;
	this->NT = BT;
}

void process::set_CT(int CT)
{
	this->CT = CT;
}

void process::calculate_WT()
{
	WT = TAT - BT;
}

void process::set_RT(int RT)
{
	this->RT = RT;
}

void process::set_NT(int NT) {
	this->NT = NT;
}

void process::calculate_TAT()
{
	TAT = CT - AT;
}

int process::get_ID() {
	return ID;
}

int process::get_AT()
{
	return AT;
}

int process::get_BT()
{
	return BT;
}

int process::get_PR()
{
	return PR;
}

int process::get_CT()
{
	return CT;
}

int process::get_WT()
{
	return WT;
}

int process::get_RT()
{
	return RT;
}

int process::get_NT() 
{
	return NT;
}

int process::get_TAT()
{
	return TAT;
}

double average_WT(int process_count, ...)
{
	va_list vl;
	double sum = 0;
	int i = 0;
	va_start(vl, process_count);
	for (i = 0; i < process_count; i++) {
		process p = va_arg(vl, process);
		sum += p.WT;
	}
	va_end(vl);
	return sum/process_count;
}

double average_RT(int process_count, ...)
{
	va_list vl;
	double sum = 0;
	int i = 0;
	va_start(vl, process_count);
	for (i = 0; i < process_count; i++) {
		process p = va_arg(vl, process);
		sum += p.RT;
	}
	va_end(vl);
	return sum / process_count;
}

double average_TAT(int process_count, ...)
{
	va_list vl;
	double sum = 0;
	int i = 0;
	va_start(vl, process_count);
	for (i = 0; i < process_count; i++) {
		process p = va_arg(vl, process);
		sum += p.TAT;
	}
	va_end(vl);
	return sum / process_count;
}

double average_WT(std::vector<process> p) {
	int i = 0;
	double sum = 0.0;
	for (; i != p.size(); i++) {
		sum += p[i].WT;
	}
	return sum / p.size();
}
double average_RT(std::vector<process> p) {
	int i = 0;
	double sum = 0.0;
	for (; i != p.size(); i++) {
		sum += p[i].RT;
	}
	return sum / p.size();
}

double average_TAT(std::vector<process> p) {
	int i = 0;
	double sum = 0.0;
	for (; i != p.size(); i++) {
		sum += p[i].TAT;
	}
	return sum / p.size();
}

#endif