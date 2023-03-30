#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void bubbleSort(vector<string>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pid_t pid1, pid2;
    pid1 = fork();

    if (pid1 == 0) {
        // Child 1 process
        bubbleSort(arr);
        cout << "Child 1 has completed bubble sort\n";
        return 0;
    } else {
        // Parent process
        pid2 = fork();
        if (pid2 == 0) {
            // Child 2 process
            selectionSort(arr);
            cout << "Child 2 has completed selection sort\n";
            return 0;
        } else {
            // Parent process
            int status;
            pid_t done_pid = wait(&status);
            if (done_pid == pid1) {
                cout << "Child 1 has terminated\n";
            } else if (done_pid == pid2) {
                cout << "Child 2 has terminated\n";
            }
            return 0;
        }
    }
}
