#include <iostream>
#include <string>
#include "Process.h"
#include "RoundRobin.h"
#include "FirstComeFirstServed.h"
#include "MultiLevelQueue.h"

using namespace std;

int main()
{
    MultiLevelQueue mlq1 = MultiLevelQueue();
    mlq1.ReadTextFile("mlq003.txt");
    mlq1.AssignQueue();
    mlq1.StartAlgorithm();
    mlq1.CalculateAverage();
    mlq1.WriteTextFile("mlq003output.txt");
}