#pragma once
#include <sstream>
#include <fstream>
#include <string>
#include "Process.h"
#include "RoundRobin.h"
#include "FirstComeFirstServed.h"

// Definition of the MultiLevelQueue class. This class is used to implement a 
// Multi-Level Queue (MLQ) scheduling algorithm that handles processes across multiple queues.

class MultiLevelQueue
{
private:
    // A list of all processes to be scheduled.
    vector<Process> processList;

    // Separate queues for processes, corresponding to different scheduling strategies.
    vector<Process> queue1; // Queue for Round Robin with quantum 1.
    vector<Process> queue2; // Queue for Round Robin with quantum 3.
    vector<Process> queue3; // Queue for Round Robin with quantum 4.
    vector<Process> queue4; // Queue for First Come First Served.

    // The current time in the simulation, used to track process execution.
    int currentTime;

    // Averages for various process metrics across all queues.
    double avgWT;  // Average Waiting Time.
    double avgCT;  // Average Completion Time.
    double avgRT;  // Average Response Time.
    double avgTAT; // Average Turnaround Time.

public:
    // Constructor for initializing member variables.
    MultiLevelQueue();

    // Reads process data from a text file and populates the process list.
    void ReadTextFile(string dir);

    // Writes the process details and statistics to a text file.
    void WriteTextFile(string dir);

    // Assigns processes to the appropriate queues based on their specified queue attribute.
    void AssignQueue();

    // Executes the scheduling algorithms for each queue and calculates relevant metrics.
    void StartAlgorithm();

    // Calculates and displays average metrics (WT, CT, RT, TAT) across all processes.
    void CalculateAverage();
};