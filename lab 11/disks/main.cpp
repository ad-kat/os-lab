#include <bits/stdc++.h>

using namespace std;

// Function to simulate the SSTF disk scheduling algorithm
int sstf(vector<int>& requests, int head_pos) {
    int n = requests.size();
    vector<bool> visited(n, false);
    int curr_pos = head_pos;
    int tot_dist = 0;
    for (int i = 0; i < n; i++) {
        int idx = -1;
        int min_dist = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = abs(requests[j] - curr_pos);
                if (dist < min_dist) {
                    min_dist = dist;
                    idx = j;
                }
            }
        }
        visited[idx] = true;
        tot_dist += min_dist;
        curr_pos = requests[idx];
    }
    return tot_dist;
}

// Function to simulate the SCAN disk scheduling algorithm
int scan(vector<int>& requests, int head_pos,int max_pos) {
    int n = requests.size();
    vector<int> req = requests;
    req.push_back(max_pos); // add boundary request
    req.push_back(0); // add boundary request
    sort(req.begin(), req.end());
    int idx = lower_bound(req.begin(), req.end(), head_pos) - req.begin();

    int idx1=idx;
    idx--;

    int tot_dist = 0;


    while (idx >= 0) {
        tot_dist += abs(head_pos - req[idx]);
        head_pos = req[idx];
        idx--;
    }
    head_pos=req[0];
    idx1++;

    while (idx1 < n + 1) {
        tot_dist += abs(head_pos - req[idx1]);
        head_pos = req[idx1];
        idx1++;
    }
    return tot_dist;
}

// Function to simulate the C-SCAN disk scheduling algorithm
int cscan(vector<int>& requests, int head_pos, int max_pos) {
    int n = requests.size();

    vector<int> req = requests;
    req.push_back(max_pos); // add boundary request
    req.push_back(0); // add boundary request
    sort(req.begin(), req.end());
    int idx = lower_bound(req.begin(), req.end(), head_pos) - req.begin();
    int idx1=req.end()-req.begin();

    int idx2=idx;
    int tot_dist = 0;
    idx--;


    while (idx >= 0) {
        tot_dist += abs(head_pos - req[idx]);

        head_pos = req[idx];
        idx--;
    }
    head_pos=req[n+1];
    idx1--;
    while (idx1 > idx2) {
        tot_dist += abs(head_pos - req[idx1]);

        head_pos = req[idx1];
        idx1--;
    }

    return tot_dist;
}

// Function to simulate the C-LOOK disk scheduling algorithm
int clook(vector<int>& requests, int head_pos, int max_pos) {
    int n = requests.size();
    vector<int> req = requests;
     // add boundary request
    sort(req.begin(), req.end());
    int idx = lower_bound(req.begin(), req.end(), head_pos) - req.begin();
     int idx1=req.end()-req.begin();

    int idx2=idx;
    int tot_dist = 0;
    idx--;


    while (idx >= 0) {
        tot_dist += abs(head_pos - req[idx]);

        head_pos = req[idx];
        idx--;
    }
    head_pos=req[n-1];
    idx1--;
    while (idx1 > idx2) {
        tot_dist += abs(head_pos - req[idx1]);

        head_pos = req[idx1];
        idx1--;
    }

    return tot_dist;
}

// Function to implement the First-Come-First-Serve (FCFS) algorithm
int fcfs(const vector<int>& requests, int head_pos) {
    int tot_dist = 0;
    int n = requests.size();
    for (int i = 0; i < n; i++) {
        tot_dist += abs(head_pos - requests[i]);
        head_pos = requests[i];
    }
    return tot_dist;
}

// Function to implement the LOOK algorithm
int look(vector<int>& requests, int head_pos, int max_pos) {
    int n = requests.size();
    vector<int> req = requests;
    req.push_back(max_pos); // add boundary request
    req.push_back(0); // add boundary request
    sort(req.begin(), req.end());
    int idx = lower_bound(req.begin(), req.end(), head_pos) - req.begin();
    int tot_dist = 0;
    while (idx >= 0 && idx < n + 2) {
        tot_dist += abs(head_pos - req[idx]);
        head_pos = req[idx];
        idx++;
    }
    idx--;
    while (idx >= 0 && idx < n + 1) {
        tot_dist += abs(head_pos - req[idx]);
        head_pos = req[idx];
        idx--;
    }
    return tot_dist;
}


int main() {
int n, head_pos, max_pos;
cout << "Enter the number of disk requests: ";
cin >> n;
cout << "Enter the starting head position: ";
cin >> head_pos;
cout << "Enter the maximum disk position: ";
cin >> max_pos;
vector<int> requests(n);
cout << "Enter the disk requests: ";
for (int i = 0; i < n; i++) {
cin >> requests[i];
}
cout << endl;
// Run each disk scheduling algorithm and output the total head movement
//cout << "SSTF: " << sstf(requests, head_pos) << endl;
//cout << "SCAN: " << scan(requests, head_pos, max_pos) << endl;
//cout << "C-SCAN: " << cscan(requests, head_pos, max_pos) << endl;
cout << "C-LOOK: " << clook(requests, head_pos, max_pos) << endl;
//cout << "FCFS: " << fcfs(requests, head_pos) << endl;
//cout << "LOOK: " << look(requests, head_pos, max_pos) << endl;
return 0;
}
