#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 100
#define URL_LENGTH 100

// Structure to represent the browser history
struct BrowserHistory {
    char history[MAX_HISTORY][URL_LENGTH]; // Stack for backward navigation
    int top; // Index for the top of the stack
};

// Function prototypes
void initializeHistory(struct BrowserHistory *history);
void visitPage(struct BrowserHistory *history, const char *url);
void goBack(struct BrowserHistory *history, char *currentPage);
void goForward(struct BrowserHistory *history, char *currentPage);
void displayCurrentPage(const char *currentPage);

int main() {
    struct BrowserHistory history;
    char currentPage[URL_LENGTH];
    char action[10];

    initializeHistory(&history);

    // Simulating visiting pages
    visitPage(&history, "google.com");
    visitPage(&history, "github.com");
    visitPage(&history, "stackoverflow.com");

    // Display the current page
    strcpy(currentPage, history.history[history.top - 1]);
    displayCurrentPage(currentPage);

    // Perform actions
    while (1) {
        printf("\nAction (Go Back / Go Forward / Exit): ");
        scanf("%s", action);

        if (strcmp(action, "Go") == 0) {
            char direction[10];
            scanf("%s", direction);
            if (strcmp(direction, "Back") == 0) {
                goBack(&history, currentPage);
            } else if (strcmp(direction, "Forward") == 0) {
                goForward(&history, currentPage);
            } else {
                printf("Invalid action!\n");
            }
        } else if (strcmp(action, "Exit") == 0) {
            break;
        } else {
            printf("Invalid action!\n");
        }
    }

    return 0;
}

// Function to initialize the browser history
void initializeHistory(struct BrowserHistory *history) {
    history->top = 0; // Start with an empty history
}

// Function to visit a new page
void visitPage(struct BrowserHistory *history, const char *url) {
    if (history->top < MAX_HISTORY) {
        strcpy(history->history[history->top], url);
        history->top++;
    } else {
        printf("History is full! Cannot visit new page.\n");
    }
}

// Function to go back in history
void goBack(struct BrowserHistory *history, char *currentPage) {
    if (history->top > 1) {
        history->top--; // Move back in history
        strcpy(currentPage, history->history[history->top - 1]);
        displayCurrentPage(currentPage);
    } else {
        printf("No previous page to go back to.\n");
    }
}

// Function to go forward in history
void goForward(struct BrowserHistory *history, char *currentPage) {
    // Forward navigation is not implemented in this simple version
    // This would require a second stack to keep track of forward history
    printf("Forward navigation is not implemented in this version.\n");
}

// Function to display the current page
void displayCurrentPage(const char *currentPage) {
    printf("Current Page: %s\n", currentPage);
}
