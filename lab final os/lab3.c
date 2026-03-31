#include <stdio.h>

int main() {
    int n, i, qt, count = 0, temp = 0, sq = 0, t = 0;
    int bt[20], at[20], wt[20], tat[20], rem_bt[20];
    float awt = 0, att = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    //C Code for Round Robin Scheduling


    // Input Arrival Time and Burst Time for each process
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P[%d] Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter Quantum Time: ");
    scanf("%d", &qt);

    int completed = 0;
    int flag = 0;
    while (completed < n) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= t) {
                flag = 1;
                if (rem_bt[i] > qt) {
                    t += qt;
                    rem_bt[i] -= qt;
                } else {
                    t += rem_bt[i];
                    tat[i] = t - at[i];
                    wt[i] = tat[i] - bt[i];
                    rem_bt[i] = 0;
                    completed++;
                }
            }
        }
        if (flag == 0) { // No process has arrived yet
            t++;
        }
    }

    printf("\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        awt += wt[i];
        att += tat[i];
        printf("P[%d]\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    awt /= n;
    att /= n;

    printf("\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", att);

    return 0;
}
