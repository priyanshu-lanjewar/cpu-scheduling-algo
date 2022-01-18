#pragma once
#include "iostream"
#include "vector"

/// <summary>
/// Function to Print Gantt Chart
/// </summary>
/// <param name="gc"></param>
void print_gantt_chart(std::vector<int> gc) {
	std::cout << "Gantt Chart =>" << std::endl;
    int k = 0,i=0;
    while (k <= gc.size()) {
        int m = 0;
        for (; m<=10; m++,k++) {
            printf("%4d ", k);
        }
        k--;
        m = 0;
        std::cout << std::endl << "   ";
        for (i; i<gc.size() && m < 10;m++, i++) {
            if (gc[i])
                printf("| P%d ", gc[i]);
            else
                printf("|IDLE");
            _sleep(1000);
        }
        while (m++<10)
        {
            printf("|IDLE");
        }
        std::cout << "|" << std::endl << std::endl;
        
    }
}