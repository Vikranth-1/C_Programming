#include <stdio.h>
#include <stdlib.h>   // for exit()

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = val;
        printf("Pushed %d\n", val);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top];
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack: ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Array Stack Menu ---\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            val = pop();
            if (val != -1) printf("Popped: %d\n", val);
            break;
        case 3:
            val = peek();
            if (val != -1) printf("Top: %d\n", val);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}