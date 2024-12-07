#pragma once
#include <iostream>
#include <string>

using namespace std;

// Definition of the `Process` class.
// Represents a process in a scheduling system and stores its attributes and state.

class Process
{
private:
    // Core attributes of the process.
    string label;        // Process label or identifier (e.g., "P1").
    int burstTime;       // Total CPU time required by the process.
    int arrivalTime;     // Time at which the process enters the system.
    int queue;           // Queue to which the process is assigned.
    int priority;        // Priority level of the process (if applicable).

    // Metrics calculated during execution.
    int completionTime = 0;    // Time at which the process completes execution.
    int turnAroundTime = 0;    // Total time from arrival to completion.
    int waitingTime = 0;       // Total time spent waiting in the ready queue.
    int responseTime = -1;     // Time from arrival to first execution (-1 indicates not executed yet).

    // Execution-related attributes.
    int executionTime = 0;     // Total time the process has executed so far.
    int currentBurstTime = 0;  // Remaining CPU time for the process.
    bool isFinished = false;   // Indicates whether the process has completed execution.

public:
    // Constructor: Initializes a process with its attributes.
    Process(string label, int bt, int at, int q, int p);

    // Getter for the process label.
    string getLabel() const;

    // Getter for the total burst time.
    int getBurstTime() const;

    // Getter for the arrival time.
    int getArrivalTime() const;

    // Getter for the assigned queue.
    int getQueue() const;

    // Getter for the priority level.
    int getPriority() const;

    // Getter and setter for the completion time.
    int getCompletionTime() const;
    void setCompletionTime(int cpt);

    // Getter and setter for the turnaround time.
    int getTurnAroundTime() const;
    void setTurnAroundTime(int tat);

    // Getter and setter for the waiting time.
    int getWaitingTime() const;
    void setWaitingTime(int wt);

    // Getter and setter for the response time.
    int getResponseTime() const;
    void setResponseTime(int rt);

    // Getter and setter for the execution time.
    int getExecutionTime() const;
    void setExecutionTime(int et);

    // Getter and setter for the current burst time.
    int getCurrentBurstTime() const;
    void setCurrentBurstTime(int cbt);

    // Getter and setter for the finished status.
    bool getIsFinished() const;
    void setIsFinished(bool f);
};