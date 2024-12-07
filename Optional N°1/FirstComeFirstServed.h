#pragma once
#include <queue>
#include <vector>
#include "Process.h"

using namespace std;

// Definition of the `FirstComeFirstServed` class.
// Implements the First-Come-First-Served (FCFS) scheduling algorithm.

class FirstComeFirstServed
{
private:
    // Attributes
    vector<Process>& processList; // Reference to the list of processes to be scheduled.
    int& currentTime;             // Reference to the current time in the system.

public:
    // Constructor
    FirstComeFirstServed(vector<Process>& pl, int& ct);

    // Methods
    void SortProcessList();  // Sorts processes based on arrival time and label.
    void StartAlgorithm();   // Simulates the FCFS scheduling process.
    void CalculateStats();   // Calculates and displays scheduling metrics.
};