#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
    printf("%d inserted at beginning.\n", data);
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("%d inserted at end.\n", data);
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("%d inserted at end.\n", data);
}

void insertAfter(Node* head, int afterValue, int data) {
    Node* temp = head;
    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("%d not found in list.\n", afterValue);
        return;
    }
    
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("%d inserted after %d.\n", data, afterValue);
}

void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node* temp = *head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("%d not found in list.\n", data);
        return;
    }
    
    if (*head == temp) {
        *head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    free(temp);
    printf("%d deleted from list.\n", data);
}

void traverseForward(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("List elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void displayMenu() {
    printf("\nDoubly Linked List Operations:\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert after a value\n");
    printf("4. Delete a value\n");
    printf("5. Display list\n");
    printf("6. Exit\n");
}

int main() {
    Node* head = NULL;
    int choice, data, afterValue;
    clrscr();
    printf("Doubly Linked List Implementation\n");
    
    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter value after which to insert: ");
                scanf("%d", &afterValue);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfter(head, afterValue, data);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 5:
                traverseForward(head);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    getch();
    return 0;
}
