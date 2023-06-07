#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    bool isCompleted;
};

bool compareArrivalTime(Process p1, Process p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

bool compareBurstTime(Process p1, Process p2) {
    return p1.burstTime < p2.burstTime;
}

void calculateTimes(Process processes[], int n) {
    sort(processes, processes + n, compareArrivalTime);

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        currentTime = processes[i].completionTime;
        processes[i].isCompleted = true;
    }
}

void displayTimes(Process processes[], int n) {
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t"
            << processes[i].completionTime << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << endl;
    }
}

void tatwt(Process processes[], int n)
{
    float avgtat=0.0,avgwt=0.0;
    int tt=0,wat=0;
    for (int i = 0; i < n; i++){
        wat+=processes[i].waitingTime;
        tt+=processes[i].turnaroundTime;
    }
    avgtat=tt/float(n);
    avgwt=wat/float(n);
    cout<<"tat avg="<<avgtat<<endl;
    cout<<"wat avg="<<avgwt<<endl;
}


int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];

    cout << "Enter arrival time and burst time for each process:" << endl;
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Process " << processes[i].id << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].isCompleted = false;
    }

    calculateTimes(processes, n);
    displayTimes(processes, n);
    tatwt(processes, n);

    return 0;
}































