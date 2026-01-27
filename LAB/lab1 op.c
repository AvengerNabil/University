#include <stdio.h>
int main() {
    int n = 3;
    int burst_time[] = {24, 3, 3};
    int waiting_time[3], turnaround_time[3];
    float avg_wt = 0, avg_tat = 0;
    waiting_time[0] = 0; // first process has no waiting time
    // Calculate waiting times
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }
    // Calculate turnaround times
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_wt += waiting_time[i];
        avg_tat += turnaround_time[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    return 0;
}
