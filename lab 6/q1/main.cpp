#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Process {
    int pid, bt, at, wt, tt, priority;
};

bool comp(Process a, Process b) {
    return a.at < b.at;
}

class Scheduler {
public:
    vector<Process> processes;
    int n;

    void getProcesses() {
        cout << "Enter the number of processes: ";
        cin >> n;
        cout << " PID \t Bt \t At \t Priority"<<endl;
        for(int i=0;i<n;i++) {
            Process p;

            cin >> p.pid>> p.bt>> p.at>> p.priority;

            p.wt = p.tt = 0;
            processes.push_back(p);
        }
        sort(processes.begin(), processes.end(), comp);
    }

    void sjf() {
        int time = processes[0].at, cnt = 0;
        vector<int> done(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({processes[0].bt, 0});
        while(!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            if(done[idx]) continue;
            done[idx] = 1;
            cnt++;
            time += processes[idx].bt;
            processes[idx].tt = time - processes[idx].at;
            processes[idx].wt = processes[idx].tt - processes[idx].bt;
            for(int i=0;i<n;i++) {
                if(!done[i] && processes[i].at <= time) {
                    pq.push({processes[i].bt, i});
                }
            }
            if(cnt == n) break;
        }
        printProcesses();
    }

    void priority() {
        int time = processes[0].at, cnt = 0;
        vector<int> done(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<n;i++) {
            if(processes[i].at <= time) {
                pq.push({processes[i].priority, i});
            }
        }
        while(!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            if(done[idx]) continue;
            done[idx] = 1;
            cnt++;
            time += processes[idx].bt;
            processes[idx].tt = time - processes[idx].at;
            processes[idx].wt = processes[idx].tt - processes[idx].bt;
            for(int i=0;i<n;i++) {
                if(!done[i] && processes[i].at <= time) {
                    pq.push({processes[i].priority, i});
                }
            }
            if(cnt == n) break;
        }
        printProcesses();
    }

    void roundRobin() {
        int time = processes[0].at, cnt = 0, quantum;
        cout << "Enter time quantum: ";
        cin >> quantum;
        vector<int> done(n, 0), rem_bt(n);
        for(int i=0;i<n;i++) {
            rem_bt[i] = processes[i].bt;
        }
        queue<int> q;
        q.push(0);
                while(!q.empty()) {
            int idx = q.front();
            q.pop();
            if(done[idx]) continue;
            int bt = min(rem_bt[idx], quantum);
            rem_bt[idx] -= bt;
            time += bt;
            if(rem_bt[idx] > 0) {
                q.push(idx);
            }
            else {
                cnt++;
                done[idx] = 1;
                processes[idx].tt = time - processes[idx].at;
                processes[idx].wt = processes[idx].tt - processes[idx].bt;
            }
            for(int i=0;i<n;i++) {
                if(!done[i] && processes[i].at <= time) {
                    q.push(i);
                }
            }
            if(q.empty()) {
                for(int i=0;i<n;i++) {
                    if(!done[i] && processes[i].at > time) {
                        time = processes[i].at;
                        q.push(i);
                        break;
                    }
                }
            }
            if(cnt == n) break;
        }
        printProcesses();
    }

    void printProcesses() {
        cout << "Process\tBT\tAT\tWT\tTT\tPriority\n";
        for(int i=0;i<n;i++) {
            cout << processes[i].pid << "\t" << processes[i].bt << "\t" << processes[i].at << "\t" << processes[i].wt << "\t" << processes[i].tt << "\t" << processes[i].priority << "\n";
        }
    }
};

int main() {
    Scheduler s;
    int choice;
    do {
        cout << "\nProcess Scheduling Algorithms:\n";
        cout << "1. Preemptive SJF\n";
        cout << "2. Non-Preemptive Priority\n";
        cout << "3. Round Robin\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                s.getProcesses();
                s.sjf();
                break;
            case 2:
                s.getProcesses();
                s.priority();
                break;
            case 3:
                s.getProcesses();
                s.roundRobin();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 4);
    return 0;
}

