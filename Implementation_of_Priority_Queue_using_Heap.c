#include <stdio.h>
#define MAX 100

int heap[MAX], n = 0;

// Function to insert an element (max-heap)
void insert(int val) {
    int i = ++n;
    while (i > 1 && val > heap[i/2]) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = val;
}

// Function to delete the highest priority element
int del() {
    int val = heap[1], last = heap[n--], i = 1, j = 2;
    while (j <= n) {
        if (j < n && heap[j] < heap[j+1]) j++;
        if (last >= heap[j]) break;
        heap[i] = heap[j];
        i = j; j *= 2;
    }
    heap[i] = last;
    return val;
}

// Display heap (priority queue)
void display() {
    for (int i = 1; i <= n; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(30); insert(50); insert(20); insert(40);
    printf("Priority Queue: "); display();
    printf("Deleted max: %d\n", del());
    printf("After deletion: "); display();
    return 0;
}
