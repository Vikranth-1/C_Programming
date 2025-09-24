#include <stdio.h>
#include <conio.h>

void main() {
    int i, a = 1, h = 2, n;
    clrscr();
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
	if (a == 1) {
	    printf("Processing %d!\n", i + 1);
	    a++;
	}
	if (h > 1) {
	    if (i + 2 <= n) {
		printf("Processing %d!\n", i + 2);
	    }
	    printf("Process %d enters critical section\n", i + 1);
	    printf("Process %d leaves critical section\n", i + 1);
	}
	h++;
    }
    getch();
}
