#include "Process.h"

// Constructor for the Process class.
// Initializes a process with its attributes:
// l: process label (identifier).
// bt: burst time (total time required by the process to complete).
// at: arrival time (when the process enters the system).
// q: queue number (used for multilevel queue scheduling).
// p: priority (used for priority-based scheduling).
Process::Process(string l, int bt, int at, int q, int p)
{
    label = l;                      // Set the process label.
    burstTime = bt;                 // Set the total burst time.
    arrivalTime = at;               // Set the arrival time.
    queue = q;                      // Assign the queue number.
    priority = p;                   // Assign the process priority.

    completionTime = 0;             // Initialize completion time to 0 (not completed yet).
    turnAroundTime = 0;             // Initialize turnaround time to 0.
    waitingTime = 0;                // Initialize waiting time to 0.
    responseTime = -1;              // Initialize response time to -1 (indicating no response yet).

    executionTime = 0;              // Execution time is initially 0.
    currentBurstTime = burstTime;   // Current burst time is equal to the total burst time initially.
    isFinished = false;             // Process is not finished at the start.
}

// Getter function for the process label.
string Process::getLabel() const
{
    return label;
}

// Getter function for the total burst time.
int Process::getBurstTime() const
{
    return burstTime;
}

// Getter function for the arrival time.
int Process::getArrivalTime() const
{
    return arrivalTime;
}

// Getter function for the queue number.
int Process::getQueue() const
{
    return queue;
}

// Getter function for the priority.
int Process::getPriority() const
{
    return priority;
}

// Getter function for the completion time.
int Process::getCompletionTime() const
{
    return completionTime;
}

// Setter function to update the completion time.
void Process::setCompletionTime(int cpt)
{
    completionTime = cpt;
}

// Getter function for the turnaround time.
int Process::getTurnAroundTime() const
{
    return turnAroundTime;
}

// Setter function to update the turnaround time.
void Process::setTurnAroundTime(int tat)
{
    turnAroundTime = tat;
}

// Getter function for the waiting time.
int Process::getWaitingTime() const
{
    return waitingTime;
}

// Setter function to update the waiting time.
void Process::setWaitingTime(int wt)
{
    waitingTime = wt;
}

// Getter function for the response time.
int Process::getResponseTime() const
{
    return responseTime;
}

// Setter function to update the response time.
void Process::setResponseTime(int rt)
{
    responseTime = rt;
}

// Getter function for the execution time.
int Process::getExecutionTime() const
{
    return executionTime;
}

// Setter function to update the execution time.
void Process::setExecutionTime(int et)
{
    executionTime = et;
}

// Getter function for the current burst time (remaining burst time).
int Process::getCurrentBurstTime() const
{
    return currentBurstTime;
}

// Setter function to update the current burst time.
void Process::setCurrentBurstTime(int cbt)
{
    currentBurstTime = cbt;
}

// Getter function to check if the process is finished.
bool Process::getIsFinished() const
{
    return isFinished;
}

// Setter function to update the finished status of the process.
void Process::setIsFinished(bool f)
{
    isFinished = f;
}