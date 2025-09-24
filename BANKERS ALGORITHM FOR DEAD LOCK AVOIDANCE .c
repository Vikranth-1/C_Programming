#include <stdio.h>

void main() {
    int allocated[15][15], max[15][15], need[15][15];
    int avail[15], totalRes[15], work[15], flag[15];
    int pno, rno, i, j, prc, count, total;

    count = 0;

    printf("\nEnter number of processes: ");
    scanf("%d", &pno);
    printf("Enter number of resources: ");
    scanf("%d", &rno);

    for(i = 1; i <= pno; i++) {
        flag[i] = 0;
    }

    printf("\nEnter total instances of each resource: ");
    for(i = 1; i <= rno; i++) {
        scanf("%d", &totalRes[i]);
    }

    printf("\nEnter Max resources for each process:\n");
    for(i = 1; i <= pno; i++) {
        printf("For process %d: ", i);
        for(j = 1; j <= rno; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Allocated resources for each process:\n");
    for(i = 1; i <= pno; i++) {
        printf("For process %d: ", i);
        for(j = 1; j <= rno; j++) {
            scanf("%d", &allocated[i][j]);
        }
    }

    // Calculate Available
    printf("\nAvailable resources:\n");
    for(j = 1; j <= rno; j++) {
        total = 0;
        for(i = 1; i <= pno; i++) {
            total += allocated[i][j];
        }
        avail[j] = totalRes[j] - total;
        work[j] = avail[j];
        printf("%d\t", work[j]);
    }

    // Calculate Need
    for(i = 1; i <= pno; i++) {
        for(j = 1; j <= rno; j++) {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    printf("\n\nAllocated | Max | Need\n");
    for(i = 1; i <= pno; i++) {
        for(j = 1; j <= rno; j++)
            printf("%3d", allocated[i][j]);
        printf(" |");
        for(j = 1; j <= rno; j++)
            printf("%3d", max[i][j]);
        printf(" |");
        for(j = 1; j <= rno; j++)
            printf("%3d", need[i][j]);
        printf("\n");
    }

    // Banker's Algorithm
    do {
        prc = 0;
        for(i = 1; i <= pno; i++) {
            if(flag[i] == 0) {
                for(j = 1; j <= rno; j++) {
                    if(work[j] < need[i][j]) {
                        break;
                    }
                }
                if(j == rno+1) {  // All resources satisfied
                    prc = i;
                    break;
                }
            }
        }

        if(prc != 0) {
            printf("\nProcess %d completed.", prc);
            count++;
            for(j = 1; j <= rno; j++) {
                work[j] += allocated[prc][j];
            }
            flag[prc] = 1;
        }
    } while(count != pno && prc != 0);

    if(count == pno)
        printf("\n\nSystem is in a SAFE state!");
    else
        printf("\n\nSystem is in an UNSAFE state!");
}
