#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data; n->prev = n->next = NULL;
    return n;
}

void insertBeg(Node **head, int data) {
    Node *n = createNode(data);
    if (*head) { n->next = *head; (*head)->prev = n; }
    *head = n;
}

void insertEnd(Node **head, int data) {
    Node *n = createNode(data), *t = *head;
    if (!t) { *head = n; return; }
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
}

void insertAfter(Node *head, int key, int data) {
    while (head && head->data != key) head = head->next;
    if (!head) return;
    Node *n = createNode(data);
    n->next = head->next; n->prev = head;
    if (head->next) head->next->prev = n;
    head->next = n;
}

void delete(Node **head, int data) {
    Node *t = *head;
    while (t && t->data != data) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next; else *head = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
}

void display(Node *h) {
    while (h) { printf("%d ", h->data); h = h->next; }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int ch, d, k;
    while (1) {
        printf("\n1.InsertBeg 2.InsertEnd 3.InsertAfter 4.Delete 5.Display 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Data: "); scanf("%d", &d); insertBeg(&head, d); break;
            case 2: printf("Data: "); scanf("%d", &d); insertEnd(&head, d); break;
            case 3: printf("After value: "); scanf("%d", &k);
                    printf("Data: "); scanf("%d", &d); insertAfter(head, k, d); break;
            case 4: printf("Delete value: "); scanf("%d", &d); delete(&head, d); break;
            case 5: display(head); break;
            case 6: exit(0);
        }
    }
}
