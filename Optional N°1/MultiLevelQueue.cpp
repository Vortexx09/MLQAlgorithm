#include "MultiLevelQueue.h"

// Constructor for the MultiLevelQueue class.
// Initializes all attributes of the MultiLevelQueue object.
MultiLevelQueue::MultiLevelQueue() {
    currentTime = 0; // Tracks the current time in the scheduling system.
    avgWT = 0;       // Average waiting time across all processes.
    avgCT = 0;       // Average completion time across all processes.
    avgRT = 0;       // Average response time across all processes.
    avgTAT = 0;      // Average turnaround time across all processes.
}

// Reads process data from a text file and populates the process list.
void MultiLevelQueue::ReadTextFile(string fileName)
{
    string dir = "C:/Users/ASRock/source/repos/Optional N°1/Resources/" + fileName; // Constructs the file path.

    ifstream textFile(dir);  // Opens the file for reading.
    string textLine;

    if (!textFile.is_open()) {
        cout << "Error al abrir archivo." << endl; // Error message if the file cannot be opened.
    }

    int lineNumber = 0;

    // Reads the file line by line.
    while (getline(textFile, textLine)) {
        lineNumber++;

        if (textLine[0] == '#') {
            continue; // Skip comment lines starting with '#'.
        }

        stringstream sstream(textLine); // Parse the line using a stringstream.
        char delimiter;

        string _label;       // Process label.
        int _burstTime;      // Burst time of the process.
        int _arrivalTime;    // Arrival time of the process.
        int _queue;          // Queue assignment.
        int _priority;       // Priority level.

        // Parse each field in the line using semicolon (';') as the delimiter.
        getline(sstream, _label, ';');
        sstream >> _burstTime >> delimiter >> _arrivalTime >> delimiter >> _queue >> delimiter >> _priority;

        // Create a new Process object and add it to the process list.
        Process newProcess = Process(_label, _burstTime, _arrivalTime, _queue, _priority);
        processList.push_back(newProcess);
    }

    textFile.close(); // Close the file after reading.
}

// Writes process and scheduling data to a text file.
void MultiLevelQueue::WriteTextFile(string fileName)
{
    string dir = "C:/Users/ASRock/source/repos/Optional N°1/Resources/" + fileName; // Constructs the file path.

    ofstream textFile(dir); // Opens the file for writing.

    if (!textFile.is_open()) {
        cout << "Error al crear el archivo." << endl; // Error message if the file cannot be opened.
        return;
    }

    // Write metadata and header row.
    textFile << "# archivo: " << fileName << "\n";
    textFile << "# etiqueta; BT; AT; Q; Pr; WT; CT; RT; TAT\n";

    // Gather all queues into a single vector for iteration.
    vector<vector<Process>> queues = { queue1, queue2, queue3, queue4 };

    // Write each process's data to the file.
    for (const auto& queue : queues) {
        for (const auto& process : queue) {
            textFile << process.getLabel() << ";"
                << process.getBurstTime() << ";"
                << process.getArrivalTime() << ";"
                << process.getQueue() << ";"
                << process.getPriority() << ";"
                << process.getWaitingTime() << ";"
                << process.getCompletionTime() << ";"
                << process.getResponseTime() << ";"
                << process.getTurnAroundTime() << "\n";
        }
    }

    // Write the calculated averages at the end of the file.
    textFile << "\nWT=" << avgWT
        << "; CT=" << avgCT
        << "; RT=" << avgRT
        << "; TAT=" << avgTAT << ";\n";

    textFile.close(); // Close the file after writing.

    cout << "Archivo generado exitosamente en " << dir << endl; // Success message.
}

// Assigns processes to the appropriate queue based on their queue attribute.
void MultiLevelQueue::AssignQueue()
{
    for (int i = 0; i < processList.size(); i++) {
        // Add the process to the respective queue.
        if (processList[i].getQueue() == 1)
            queue1.push_back(processList[i]);
        else if (processList[i].getQueue() == 2)
            queue2.push_back(processList[i]);
        else if (processList[i].getQueue() == 3)
            queue3.push_back(processList[i]);
        else if (processList[i].getQueue() == 4)
            queue4.push_back(processList[i]);
    }
}

// Executes the scheduling algorithm for each queue.
void MultiLevelQueue::StartAlgorithm()
{
    // Execute Round Robin scheduling for Queue 1 with a quantum of 1.
    RoundRobin rr1 = RoundRobin(queue1, currentTime, 1);
    rr1.SortProcessList();
    rr1.StartAlgorithm();
    rr1.CalculateStats();

    // Execute Round Robin scheduling for Queue 2 with a quantum of 3.
    RoundRobin rr2 = RoundRobin(queue2, currentTime, 3);
    rr2.SortProcessList();
    rr2.StartAlgorithm();
    rr2.CalculateStats();

    // Execute Round Robin scheduling for Queue 3 with a quantum of 4.
    RoundRobin rr3 = RoundRobin(queue3, currentTime, 4);
    rr3.SortProcessList();
    rr3.StartAlgorithm();
    rr3.CalculateStats();

    // Execute First Come First Serve scheduling for Queue 4.
    FirstComeFirstServed fcfs = FirstComeFirstServed(queue4, currentTime);
    fcfs.SortProcessList();
    fcfs.StartAlgorithm();
    fcfs.CalculateStats();
}

// Calculates the average statistics (WT, CT, RT, TAT) across all processes.
void MultiLevelQueue::CalculateAverage()
{
    double totalWT = 0;   // Total waiting time.
    double totalCT = 0;   // Total completion time.
    double totalRT = 0;   // Total response time.
    double totalTAT = 0;  // Total turnaround time.
    double totalProcesses = 0;

    // Combine all queues into a single vector for iteration.
    vector<vector<Process>> queues = { queue1, queue2, queue3, queue4 };

    // Calculate the totals by iterating through all processes.
    for (const auto& queue : queues) {
        for (const auto& process : queue) {
            totalWT += process.getWaitingTime();
            totalCT += process.getCompletionTime();
            totalRT += process.getResponseTime();
            totalTAT += process.getTurnAroundTime();
            totalProcesses++;
        }
    }

    // Compute averages.
    double n = processList.size();
    avgWT = totalWT / n;
    avgCT = totalCT / n;
    avgRT = totalRT / n;
    avgTAT = totalTAT / n;

    // Output the averages to the console.
    cout << "AVERAGE WT: " << avgWT << "\t"
        << "AVERAGE CT: " << avgCT << "\t"
        << "AVERAGE RT: " << avgRT << "\t"
        << "AVERAGE TAT: " << avgTAT << "\t"
        << endl;
}