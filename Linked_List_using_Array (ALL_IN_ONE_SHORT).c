#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int *arr;
    int size;
    int cap;
} ArrayList;

ArrayList* createList() {
    ArrayList l = (ArrayList)malloc(sizeof(ArrayList));
    l->cap = INITIAL_CAPACITY;
    l->arr = (int*)malloc(l->cap * sizeof(int));
    l->size = 0;
    return l;
}

void resize(ArrayList *l) {
    l->cap *= 2;
    l->arr = (int*)realloc(l->arr, l->cap * sizeof(int));
    printf("\nList resized to %d\n", l->cap);
}

void add(ArrayList *l, int val) {
    if (l->size == l->cap) resize(l);
    l->arr[l->size++] = val;
}

void insert(ArrayList *l, int idx, int val) {
    int i;
    if (idx < 0 || idx > l->size) { printf("\nInvalid index\n"); return; }
    if (l->size == l->cap) resize(l);
    for (i = l->size; i > idx; i--) l->arr[i] = l->arr[i-1];
    l->arr[idx] = val;
    l->size++;
}

int get(ArrayList *l, int idx) {
    if (idx < 0 || idx >= l->size) { printf("\nInvalid index\n"); return -1; }
    return l->arr[idx];
}

int removeAt(ArrayList *l, int idx) {
    int i, val;
    if (idx < 0 || idx >= l->size) { printf("\nInvalid index\n"); return -1; }
    val = l->arr[idx];
    for (i = idx; i < l->size-1; i++) l->arr[i] = l->arr[i+1];
    l->size--;
    return val;
}

void printList(ArrayList *l) {
    int i;
    printf("[");
    for (i = 0; i < l->size; i++) {
        printf("%d", l->arr[i]);
        if (i < l->size - 1) printf(", ");
    }
    printf("]\n");
}

void clear(ArrayList *l) { l->size = 0; }
void destroy(ArrayList *l) { free(l->arr); free(l); }

void menu() {
    printf("\n1.Add 2.Insert 3.Get 4.Remove 5.Print 6.Clear 7.Exit\n");
}

void main() {
    ArrayList *l = createList();
    int ch, val, idx;
    clrscr();
    printf("Array List (Turbo C Version)\n");

    while (1) {
        menu();
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &val); add(l, val); break;
            case 2: printf("Enter index and value: "); scanf("%d %d", &idx, &val); insert(l, idx, val); break;
            case 3: printf("Enter index: "); scanf("%d", &idx);
                    val = get(l, idx); if (val != -1) printf("Value: %d\n", val); break;
            case 4: printf("Enter index: "); scanf("%d", &idx);
                    val = removeAt(l, idx); if (val != -1) printf("Removed %d\n", val); break;
            case 5: printList(l); break;
            case 6: clear(l); printf("List cleared\n"); break;
            case 7: destroy(l); printf("Exit\n"); getch(); exit(0);
            default: printf("Invalid\n");
        }
    }
}
