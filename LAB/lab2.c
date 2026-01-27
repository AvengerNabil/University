#include <iostream>
using namespace std;

int main() {
    int n;
    int tt = 0;
    int min;
    int d = 0;
    int i, j;

    float avg_tat = 0;
    float avg_wt = 0;
    float t_tat = 0;
    float t_wt = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    int P[n], a[n], b[n], c[n], tat[n], wt[n];

    cout << "Enter process sequence:\n";
    for (i = 0; i < n; i++) {
        cin >> P[i];
    }

    cout << "Enter arrival time:\n";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter burst time:\n";
    for (i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Sorting according to burst time (SJF)
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                swap(b[i], b[j]);
                swap(a[i], a[j]);
                swap(P[i], P[j]);
            }
        }
    }

    // Find process with minimum arrival time
    min = a[0];
    for (i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
            d = i;
        }
    }

    tt = min;
    c[d] = tt + b[d];
    tt = c[d];

    // Calculate completion times
    for (i = 0; i < n; i++) {
        if (i != d) {
            if (a[i] > tt)
                tt = a[i]; // CPU idle till process arrives
            c[i] = tt + b[i];
            tt = c[i];
        }
    }

    // Display table
    cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (i = 0; i < n; i++) {
        tat[i] = c[i] - a[i];
        wt[i] = tat[i] - b[i];
        t_tat += tat[i];
        t_wt += wt[i];

        cout << "P[" << P[i] << "]\t" << a[i] << "\t" << b[i] << "\t"
             << c[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }

    avg_tat = t_tat / n;
    avg_wt = t_wt / n;

    cout << "\nAverage Turnaround Time: " << avg_tat << endl;
    cout << "Average Waiting Time: " << avg_wt << endl;

    return 0;
}
