#include "FirstComeFirstServed.h"

// Constructor for the FirstComeFirstServed class.
// Takes a reference to a process list and the current time, and initializes the member variables.
FirstComeFirstServed::FirstComeFirstServed(vector<Process>& pl, int& ct)
    : processList(pl), currentTime(ct) {}

// Sorts the process list based on arrival time (primary) and label (secondary).
void FirstComeFirstServed::SortProcessList()
{
    // Use std::sort to order processes. Priority is given to arrival time; 
    // if two processes have the same arrival time, they are sorted by their label.
    sort(processList.begin(), processList.end(), [](Process& p1, Process& p2) {
        if (p1.getArrivalTime() != p2.getArrivalTime()) {
            return p1.getArrivalTime() < p2.getArrivalTime(); // Sort by arrival time.
        }
        return p1.getLabel() < p2.getLabel(); // Sort alphabetically by label if arrival times are equal.
        });
}

// Executes the First-Come-First-Served (FCFS) scheduling algorithm.
void FirstComeFirstServed::StartAlgorithm()
{
    // Iterate over the list of processes.
    for (size_t i = 0; i < processList.size(); i++) {
        // If the current time is earlier than the arrival time of the process,
        // move the current time forward to the process's arrival time.
        if (processList[i].getArrivalTime() > currentTime) {
            currentTime = processList[i].getArrivalTime();
        }

        // Record the start time for this process.
        int startTime = currentTime;

        // Update the current time to include the process's burst time.
        currentTime += processList[i].getBurstTime();

        // Set the process's completion time based on the updated current time.
        processList[i].setCompletionTime(currentTime);
    }
}

// Calculates and prints the scheduling statistics for each process.
void FirstComeFirstServed::CalculateStats()
{
    // Print the column headers for the output.
    cout << "LB" << "\t" << "WT" << "\t" << "CT" << "\t" << "RT" << "\t" << "TAT " << endl;

    // Iterate through each process in the list.
    for (int i = 0; i < processList.size(); i++) {
        // Calculate Turnaround Time (TAT): Completion Time - Arrival Time.
        int tat = processList[i].getCompletionTime() - processList[i].getArrivalTime();
        processList[i].setTurnAroundTime(tat);

        // Calculate Waiting Time (WT): Turnaround Time - Burst Time.
        int wt = processList[i].getTurnAroundTime() - processList[i].getBurstTime();
        processList[i].setWaitingTime(wt);

        // Calculate Response Time (RT): Waiting Time + Arrival Time.
        int rt = wt + processList[i].getArrivalTime();
        processList[i].setResponseTime(rt);

        // Output the statistics for the current process.
        cout << processList[i].getLabel() << "\t"
            << processList[i].getWaitingTime() << "\t"
            << processList[i].getCompletionTime() << "\t"
            << processList[i].getResponseTime() << "\t"
            << processList[i].getTurnAroundTime() << endl;
    }

    // Print the final value of the current time after all processes have been executed.
    cout << "Current Time: " << currentTime << endl;
}