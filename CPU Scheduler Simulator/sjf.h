#pragma once

#ifndef _SJF_
#define _SJF_
#ifndef _PROCESS_
#include "process.h"
#endif
#ifndef _VECTOR_
#include "vector"
#endif
#ifndef _QUEUE_
#include "queue"
#endif
#ifndef _ALGORITHM_
#include "algorithm"
#endif
#ifndef _STATS_
#include "stats.h"
#endif

struct cmpBT {
	bool operator()(process& x, process& y) const {
			return x.get_BT() < y.get_BT();
	}
};

class sjf {
private:
	std::vector<process> table;
	std::vector<int> gantt_chart;
	std::queue<process> tq;
	std::queue<process> aq;
	std::vector<process> bq;
	double AWT;
	double ART;
	double ATAT;
	void compute_AWT();
	void compute_ART();
	void compute_ATAT();
public:
	sjf(std::vector<process> table);
	void perform_sjf();
	std::vector<int> get_gantt_chart();
	friend void print_stats(sjf sj);
};

sjf::sjf(std::vector<process> table) {
	this->table = table;
}

void sjf::compute_AWT() {
	AWT = average_WT(table);
}

void sjf::compute_ART() {
	ART = average_RT(table);
}

void sjf::compute_ATAT() {
	ATAT = average_TAT(table);
}


void sjf::perform_sjf() {
	int t = 0;
	sort(table.begin(), table.end(), cmpAT());
	for (int i = 0; i < table.size(); i++) {
		//std::cout << " " << table[i].get_ID();
		tq.push(table[i]);
	}
	int c = table.size();
	table.clear();
	while (c) {
		
		int tqs = tq.size();
		for (int i = 0; i < tqs; i++) {
			process p = tq.front();
			if (p.get_AT() <= t) {
				aq.push(p);
				tq.pop();
			}
			else {
				tq.push(tq.front());
				tq.pop();
			}
		}
		if (aq.empty() && bq.empty()) {
			t++;
			gantt_chart.push_back(0);
		}else 
		{
			
			int k = aq.size();
			for (int i = 0; i < k; i++) {
				process p = aq.front();
				bq.push_back(p);
				aq.pop();
			}

			sort(bq.begin(), bq.end(), cmpBT());
			
			process p = bq[0];
			p.set_RT(t - p.get_AT());
			while (p.get_NT() != 0) {
				gantt_chart.push_back(p.get_ID());
				p.set_NT(p.get_NT() - 1);
				t++;
			}
			c--;
			std::reverse(bq.begin(), bq.end());
			bq.pop_back();
			p.set_CT(t);
			p.calculate_TAT();
			p.calculate_WT();
			table.push_back(p);
		}
	}
	compute_ART();
	compute_AWT();
	compute_ATAT();
}

std::vector<int> sjf::get_gantt_chart() {
	return gantt_chart;
}

void print_stats(sjf sj) {
	std::cout << "STATISTICS OF SHORTEST JOB FIRST => " << std::endl;
	std::cout << "Average Response Time : " << sj.ART << std::endl;
	std::cout << "Average Waiting Time : " << sj.AWT << std::endl;
	std::cout << "Average Turn Around Time : " << sj.ATAT << std::endl;
}
#endif