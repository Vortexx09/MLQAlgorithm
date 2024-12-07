#include "RoundRobin.h"
#include "Process.h"

// Constructor initializes the RoundRobin class with a list of processes (pl), 
// a reference to the current time (ct), and the time quantum (qt).
RoundRobin::RoundRobin(vector<Process>& pl, int& ct, int qt)
    : processList(pl), currentTime(ct), quantum(qt) {}

// This function sorts the process list by arrival time. 
// If two processes have the same arrival time, they are sorted by their labels.
void RoundRobin::SortProcessList()
{
    sort(processList.begin(), processList.end(), [](Process& p1, Process& p2) {
        if (p1.getArrivalTime() != p2.getArrivalTime()) {
            return p1.getArrivalTime() < p2.getArrivalTime();
        }
        return p1.getLabel() < p2.getLabel();
        });
}

// Implements the Round Robin scheduling algorithm.
void RoundRobin::StartAlgorithm()
{
    int i = 0; // Index of the current process being executed.
    int processFinished = 0; // Keeps track of the number of finished processes.

    while (true) {
        processFinished = 0;

        // Skip processes that are already finished.
        if (processList[i].getIsFinished()) {
            i = (i + 1) % processList.size(); // Move to the next process (circularly).
            continue;
        }

        // Set the response time if it's the first time the process gets CPU time.
        if (processList[i].getResponseTime() == -1) {
            processList[i].setResponseTime(currentTime);
        }

        // Execute the process for the time quantum if its burst time is greater than the quantum.
        if (processList[i].getCurrentBurstTime() > quantum) {
            currentTime += quantum; // Increment the current time by the quantum.
            processList[i].setCurrentBurstTime(processList[i].getCurrentBurstTime() - quantum); // Reduce burst time.
        }
        // Otherwise, finish the process and update its completion time.
        else {
            currentTime += processList[i].getCurrentBurstTime(); // Add remaining burst time to the current time.
            processList[i].setCurrentBurstTime(0); // Set remaining burst time to 0.
            processList[i].setCompletionTime(currentTime); // Set the completion time.
            processList[i].setIsFinished(true); // Mark the process as finished.
        }

        // Move to the next process (circularly).
        i = (i + 1) % processList.size();

        // Check how many processes are finished.
        for (int j = 0; j < processList.size(); j++) {
            if (processList[j].getIsFinished()) {
                processFinished++;
            }
        }

        // Break the loop if all processes are finished.
        if (processFinished == processList.size()) {
            break;
        }
    }
}

// Calculates and displays the scheduling statistics for each process.
void RoundRobin::CalculateStats()
{
    // Labels for the debug table.
    cout << "LB" << "\t" << "WT" << "\t" << "CT" << "\t" << "RT" << "\t" << "TAT " << endl;

    for (int i = 0; i < processList.size(); i++) {
        // Turnaround Time (TAT) = Completion Time (CT) - Arrival Time (AT)
        int tat = processList[i].getCompletionTime() - processList[i].getArrivalTime();
        processList[i].setTurnAroundTime(tat);

        // Waiting Time (WT) = Turnaround Time (TAT) - Burst Time (BT)
        int wt = processList[i].getTurnAroundTime() - processList[i].getBurstTime();
        processList[i].setWaitingTime(wt);

        // Print the stats for the current process.
        cout << processList[i].getLabel() << "\t"
            << processList[i].getWaitingTime() << "\t"
            << processList[i].getCompletionTime() << "\t"
            << processList[i].getResponseTime() << "\t"
            << processList[i].getTurnAroundTime() << endl;
    }

    // Print the final value of the current time for debug purposes. 
    cout << "Current Time: " << currentTime << endl;
}