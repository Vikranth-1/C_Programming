#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* array;
    int size;
    int capacity;
} ArrayListADT;

// Create a new list with default capacity
ArrayListADT* createArrayList() {
    ArrayListADT* list = (ArrayListADT*)malloc(sizeof(ArrayListADT));
    list->capacity = 10;
    list->array = (int*)malloc(list->capacity * sizeof(int));
    list->size = 0;
    return list;
}

// Create a new list with custom capacity
ArrayListADT* createArrayListWithCapacity(int initialCapacity) {
    if (initialCapacity <= 0) {
        printf("Initial capacity must be positive\n");
        return NULL;
    }
    
    ArrayListADT* list = (ArrayListADT*)malloc(sizeof(ArrayListADT));
    list->capacity = initialCapacity;
    list->array = (int*)malloc(list->capacity * sizeof(int));
    list->size = 0;
    return list;
}

// Resize the array when full
void resize(ArrayListADT* list) {
    list->capacity *= 2;
    list->array = (int*)realloc(list->array, list->capacity * sizeof(int));
    printf("List resized to capacity %d\n", list->capacity);
}

// Add an element to the end of the list
void add(ArrayListADT* list, int element) {
    if (list->size == list->capacity) {
        resize(list);
    }
    list->array[list->size] = element;
    list->size++;
}

// Insert an element at a specific position
void insert(ArrayListADT* list, int index, int element) {
    if (index < 0 || index > list->size) {
        printf("Index out of bounds (0-%d)\n", list->size);
        return;
    }
    
    if (list->size == list->capacity) {
        resize(list);
    }
    
    for (int i = list->size; i > index; i--) {
        list->array[i] = list->array[i-1];
    }
    
    list->array[index] = element;
    list->size++;
}

// Get the element at a specific position
int get(ArrayListADT* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds (0-%d)\n", list->size-1);
        return -1;
    }
    return list->array[index];
}

// Remove an element at a specific position
int removeAt(ArrayListADT* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of bounds (0-%d)\n", list->size-1);
        return -1;
    }
    
    int removedElement = list->array[index];
    
    for (int i = index; i < list->size - 1; i++) {
        list->array[i] = list->array[i+1];
    }
    
    list->size--;
    return removedElement;
}

// Check if the list contains a specific element
bool contains(ArrayListADT* list, int element) {
    for (int i = 0; i < list->size; i++) {
        if (list->array[i] == element) {
            return true;
        }
    }
    return false;
}

// Get the size of the list
int size(ArrayListADT* list) {
    return list->size;
}

// Check if the list is empty
bool isEmpty(ArrayListADT* list) {
    return list->size == 0;
}

// Clear the list
void clear(ArrayListADT* list) {
    list->size = 0;
}

// Print the list
void printList(ArrayListADT* list) {
    if (list->size == 0) {
        printf("[]\n");
        return;
    }
    
    printf("[");
    for (int i = 0; i < list->size - 1; i++) {
        printf("%d, ", list->array[i]);
    }
    printf("%d]\n", list->array[list->size - 1]);
}

// Free memory when done
void destroyArrayList(ArrayListADT* list) {
    free(list->array);
    free(list);
}

// Display menu options
void displayMenu() {
    printf("\nList ADT Operations:\n");
    printf("1. Add element\n");
    printf("2. Insert element at index\n");
    printf("3. Get element at index\n");
    printf("4. Remove element at index\n");
    printf("5. Check if element exists\n");
    printf("6. Get size\n");
    printf("7. Check if empty\n");
    printf("8. Clear list\n");
    printf("9. Print list\n");
    printf("10. Exit\n");
}

int main() {
    ArrayListADT* list = createArrayList();
    int choice, value, index;
    
    printf("List ADT Implementation in C\n");
    printf("----------------------------\n");
    
    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                add(list, value);
                printf("Added %d to the list.\n", value);
                break;
            case 2:
                printf("Enter index and value to insert (index value): ");
                scanf("%d %d", &index, &value);
                insert(list, index, value);
                break;
            case 3:
                printf("Enter index to get: ");
                scanf("%d", &index);
                value = get(list, index);
                if(value != -1) {
                    printf("Element at index %d: %d\n", index, value);
                }
                break;
            case 4:
                printf("Enter index to remove: ");
                scanf("%d", &index);
                value = removeAt(list, index);
                if(value != -1) {
                    printf("Removed %d from index %d.\n", value, index);
                }
                break;
            case 5:
                printf("Enter value to check: ");
                scanf("%d", &value);
                if(contains(list, value)) {
                    printf("List contains %d.\n", value);
                } else {
                    printf("List does not contain %d.\n", value);
                }
                break;
            case 6:
                printf("Current list size: %d\n", size(list));
                break;
            case 7:
                printf("List is %s.\n", isEmpty(list) ? "empty" : "not empty");
                break;
            case 8:
                clear(list);
                printf("List cleared.\n");
                break;
            case 9:
                printf("Current list: ");
                printList(list);
                break;
            case 10:
                destroyArrayList(list);
                printf("Program exited.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
