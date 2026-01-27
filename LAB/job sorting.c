#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int pid[n], bt[n], wt[n], tat[n];
    float avg_wt = 0, avg_tat = 0;

    // Input burst times
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter burst time for process P" << pid[i] << ": ";
        cin >> bt[i];
    }

    // Sort processes by burst time (SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    wt[0] = 0; // First process waiting time = 0
    for (int i = 1; i < n; i++) {
        wt[i] = 0;
        for (int j = 0; j < i; j++)
            wt[i] += bt[j];
        avg_wt += wt[i];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time";
    for (int i = 0; i < n; i++) {
        cout << "\nP" << pid[i] << "\t\t" << bt[i] << "\t\t"
             << wt[i] << "\t\t" << tat[i];
    }

    cout << "\n\nAverage Waiting Time: " << avg_wt;
    cout << "\nAverage Turnaround Time: " << avg_tat << endl;

    return 0;
}
