#pragma once
#include <queue>
#include <vector>
#include "Process.h"

using namespace std;

// Definition of the `RoundRobin` class.
// Implements the Round Robin (RR) scheduling algorithm.

class RoundRobin
{
private:
    // Attributes
    vector<Process>& processList; // Reference to the list of processes to be scheduled.
    int& currentTime;             // Reference to the current time in the system.
    int quantum;                  // Time quantum for the Round Robin algorithm.

public:
    // Constructor
    RoundRobin(vector<Process>& pl, int& ct, int qt);

    // Methods
    void SortProcessList();  // Sorts processes based on arrival time and label.
    void StartAlgorithm();   // Simulates the Round Robin scheduling process.
    void CalculateStats();   // Calculates and displays scheduling metrics.
};