#include <stdio.h>
#include <stdlib.h>   // for exit()

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = val;
        printf("Enqueued %d\n", val);
    }
}

int dequeue() {
    int val;
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    val = queue[front];
    front++;
    return val;
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Array Queue Menu ---\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            if (val != -1) printf("Dequeued: %d\n", val);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}