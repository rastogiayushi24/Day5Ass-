#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

// Structure to represent the warehouse stock
struct Warehouse {
    char items[MAX_ITEMS][ITEM_NAME_LENGTH]; 
    int top;
};

// Function prototypes
void initializeWarehouse(struct Warehouse *warehouse);
void addItem(struct Warehouse *warehouse, const char *item);
void dispatchItem(struct Warehouse *warehouse);
void displayRemainingStock(const struct Warehouse *warehouse);

int main() {
    struct Warehouse warehouse;
    char item[ITEM_NAME_LENGTH];
    char action[10];

    initializeWarehouse(&warehouse);

    // Simulating adding items to the warehouse
    addItem(&warehouse, "Item A");
    addItem(&warehouse, "Item B");
    addItem(&warehouse, "Item C");

    // Display remaining stock
    displayRemainingStock(&warehouse);

    // Dispatching items
    while (1) {
        printf("\nAction (Dispatch / Exit): ");
        scanf("%s", action);

        if (strcmp(action, "Dispatch") == 0) {
            dispatchItem(&warehouse);
        } else if (strcmp(action, "Exit") == 0) {
            break;
        } else {
            printf("Invalid action! Please enter 'Dispatch' or 'Exit'.\n");
        }
    }

    return 0;
}

// Function to initialize the warehouse
void initializeWarehouse(struct Warehouse *warehouse) {
    warehouse->top = -1; // Start with an empty stack
}

// Function to add an item to the warehouse
void addItem(struct Warehouse *warehouse, const char *item) {
    if (warehouse->top < MAX_ITEMS - 1) {
        warehouse->top++;
        strcpy(warehouse->items[warehouse->top], item);
        printf("Stock Added: %s\n", item);
    } else {
        printf("Warehouse is full! Cannot add new item.\n");
    }
}

// Function to dispatch an item from the warehouse
void dispatchItem(struct Warehouse *warehouse) {
    if (warehouse->top >= 0) {
        printf("Dispatching Item: %s\n", warehouse->items[warehouse->top]);
        warehouse->top--; 
    } else {
        printf("No items to dispatch.\n");
    }
}

// Function to display remaining stock
void displayRemainingStock(const struct Warehouse *warehouse) {
    if (warehouse->top >= 0) {
        printf("Remaining Stock: ");
        for (int i = 0; i <= warehouse->top; i++) {
            printf("%s", warehouse->items[i]);
            if (i < warehouse->top) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("No items in stock.\n");
    }
}
