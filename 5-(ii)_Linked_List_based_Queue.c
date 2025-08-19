#include <stdio.h>
#include <stdlib.h>   // for malloc() and exit()

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d\n", val);
}

int dequeue() {
    int val;
    struct Node* temp;
    if (front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }
    val = front->data;
    temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}

void display() {
    struct Node* temp = front;
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Linked List Queue Menu ---\n");
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