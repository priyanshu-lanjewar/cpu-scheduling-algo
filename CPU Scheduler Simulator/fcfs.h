#pragma once

#ifndef _FCFS_
#define _FCFS_
#include "process.h"
#include "vector"
#include "queue"
#include "algorithm"
/// <summary>
/// FCFS :
/// This Class Contains components to simulate
/// First Come First Serve CPU Scheduling Algorithm 
/// </summary>
/// 

struct cmpAT {
	bool operator()(process& x, process& y) const {
		return x.get_AT() < y.get_AT();
	}
};

class fcfs
{
private:
	std::vector<process> table;
	std::vector<int> gantt_chart;
	std::queue<process> readyqueue;
	double AWT;
	double ART;
	double ATAT;
	void compute_AWT();
	void compute_ART();
	void compute_ATAT();
public:
	fcfs(std::vector<process> table);
	void perform_fcfs();
	std::vector<int> get_gantt_chart();
	friend void print_stats(fcfs f);
};

fcfs::fcfs(std::vector<process> table) {
	this->table = table;
}

void fcfs::compute_AWT() {
	AWT = average_WT(table);
}

void fcfs::compute_ART() {
	ART = average_RT(table);
}

void fcfs::compute_ATAT() {
	ATAT = average_TAT(table);
}

void fcfs::perform_fcfs() {
	sort(table.begin(), table.end(), cmpAT());
	for (int i = 0; i!=table.size(); i++) {
		readyqueue.push(table[i]);
	}
	table.clear();
	int t = 0;
	while (!readyqueue.empty()) {
		process p = readyqueue.front();
		readyqueue.pop();
		while (t < p.get_AT()) {
			gantt_chart.push_back(0);
			t++;
		}
		p.set_RT(t - p.get_AT());
		while (p.get_NT() != 0) {
			
			gantt_chart.push_back(p.get_ID());
			p.set_NT(p.get_NT() - 1);
			t++;
		}
		p.set_CT(t);
		p.calculate_TAT();
		p.calculate_WT();
		table.push_back(p);
	}
	compute_ART();
	compute_AWT();
	compute_ATAT();
}

std::vector<int> fcfs::get_gantt_chart()
{
	return gantt_chart;
}

void print_stats(fcfs f) {
	std::cout << "STATISTICS OF FIRST COME FIRST SERVE => " << std::endl;
	std::cout << "Average Response Time : " << f.ART << std::endl;
	std::cout << "Average Waiting Time : " << f.AWT << std::endl;
	std::cout << "Average Turn Around Time : " << f.ATAT << std::endl;
};


#endif