#include <stdio.h>
////Shortest Job First Algorithm
int main() {
    int n, tt = 0, min, d = 0, i, j;
    float avg_tat = 0, avg_wt = 0, t_tat = 0, t_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int P[n], a[n], b[n], c[n], tat[n], wt[n], completed[n];

    printf("Enter process sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &P[i]);
        completed[i] = 0; // Initialize tracking for completion
    }

    printf("Enter arrival time:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter burst time:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int total_completed = 0;
    int current_time = 0;

    // Logic for Non-Preemptive SJF
    while (total_completed < n) {
        int idx = -1;
        int min_burst = 10000; // Infinity

        // Find the process that has arrived and has the shortest burst time
        for (i = 0; i < n; i++) {
            if (a[i] <= current_time && completed[i] == 0) {
                if (b[i] < min_burst) {
                    min_burst = b[i];
                    idx = i;
                }
                // Tie-breaker: If burst times are equal, pick earlier arrival
                else if (b[i] == min_burst) {
                    if (a[i] < a[idx]) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            // Process found
            c[idx] = current_time + b[idx];
            tat[idx] = c[idx] - a[idx];
            wt[idx] = tat[idx] - b[idx];

            t_tat += tat[idx];
            t_wt += wt[idx];

            current_time = c[idx];
            completed[idx] = 1;
            total_completed++;
        } else {
            // No process has arrived, jump time to next arrival
            current_time++;
        }
    }

    // Display table
    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t\t%d\t\t%d\n",
                P[i], a[i], b[i], c[i], tat[i], wt[i]);
    }

    avg_tat = t_tat / n;
    avg_wt = t_wt / n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);

    return 0;
}
