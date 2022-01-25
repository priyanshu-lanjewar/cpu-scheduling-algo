# CPU Scheduler Simulator
## An application to simulate few CPU scheduling Policies.

![](https://img.shields.io/badge/Language-C%2B%2B-brightgreen) ![](https://img.shields.io/badge/Compiler-Visual%20C%2B%2B-yellow) ![](https://img.shields.io/badge/IDE-Microsoft%20Visual%20Studio%202022-blue) ![](https://img.shields.io/badge/Environment-Windows-red) ![](https://img.shields.io/badge/User%20Interface-GUI%20%2B%20CLI-yellowgreen)

---
## Overview
One of the main tasks of an operating system is scheduling processes to run on the CPU. The goal
of this programming project is to implement a simulator with different scheduling algorithms. 
The simulator should select a process to run from the ready queue based on the scheduling 
algorithm chosen at runtime. (It does not require any actual process creation or execution.)

### Algorithms
- First Come First Serve CPU Scheduling Algorithm
- Shortest Job First CPU Scheduling Algorithm
- Shortest Remaining Time First CPU Scheduling Algorithm
- Round Robin CPU Scheduling Algorithm

### Features
- Creation of Process table (Inputing Details of Process)
- Performing Algorithm (fcfsm,sjf,srtf,round robin)
- Computes Completion time, Waiting time, Response time and Turn Around Time for Every Process
- Computes Average Response time, Averge Waiting time and Average Turn Around Time for all Algorithms.
- Print Gantt Chart

### Header Files
## process
> header file storing attributes related to process and functions to perform operation on them
> ID : Process ID
> AT : Arrival Time
> BT : Burst Time
> CT : Completion Time
> RT : Response Time
> WT : Waiting Time
> TAT : Turn Around Time
All the required information of other attributes/ functions are explained in comments in code file itself.

## fcfs
> header file storing attributes related to fcfs and functions to perform fcfs 
All the required information of other attributes/ functions are explained in comments in code file itself.

## sjf
> header file storing attributes related to fcfs and functions to perform sjf
All the required information of other attributes/ functions are explained in comments in code file itself.

## srtf
> header file storing attributes related to fcfs and functions to perform srtf
All the required information of other attributes/ functions are explained in comments in code file itself.

## roundrobin
> header file storing attributes related to fcfs and functions to perform roundrobin
All the required information of other attributes/ functions are explained in comments in code file itself.

## gcp
> To print gantt chart
All the required information of other attributes/ functions are explained in comments in code file itself.

## cpuschalgo
> Single header to bind all above headers together

## createprocesstable
> GUI Components + backend for creating Process Table

## simulator
> GUI Components + backend for Final Result

## gui
> GUI Components + backend for GUI Entry Point

## climode
> CLI Mode Entry Point

