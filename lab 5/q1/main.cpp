#include <iostream>
#include <unistd.h>
using namespace std;
int main() {
    pid_t pid = fork();

    if (pid == -1) {
        cout << "Error " << endl;
        return 0;
    }
    else if (pid == 0) {
        // Child process
        cout << "Child process with PID " << getpid() << " created." << endl;
        cout << "Parent process PID: " << getppid() << endl;
    }
    else {
        // Parent process
        cout << "Parent process with PID " << pid <<endl;

    }

    return 0;
}
