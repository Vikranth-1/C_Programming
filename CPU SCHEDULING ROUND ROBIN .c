#include <stdio.h>
#include <conio.h>

void main() {
    int n, i, qt, count = 0, temp, sq = 0;
    int bt[10], wt[10], tat[10], rem_bt[10];
    float awt = 0, atat = 0;
    int done;
 
    clrscr();

    printf("Enter the number of processes : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the process time for process %d : ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter the time slice : ");
    scanf("%d", &qt);

    /* Round Robin execution and Gantt chart printing */
    while (1) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                printf("%d P%d ", sq, i + 1);
                if (rem_bt[i] > qt) {
                    sq += qt;
                    rem_bt[i] -= qt;
                } else {
                    sq += rem_bt[i];
                    rem_bt[i] = 0;
                }
                printf("%d\n", sq);
                tat[i] = sq;
            }
        }
        if (done == 1)
            break;
    }

    /* Calculate waiting time & averages */
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    /* Display waiting times */
    for (i = 0; i < n; i++) {
        printf("%d\n", wt[i]);
    }

    /* Display turnaround times */
    for (i = 0; i < n; i++) {
        printf("%d\n", tat[i]);
    }

    printf("Average waiting time = %f msec\n", awt / n);
    printf("Average turnaround time = %f\n", atat / n);

    getch();
}

