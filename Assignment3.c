#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SONG_NAME_LENGTH 100

// Structure to represent a song in the playlist
struct Song {
    char name[SONG_NAME_LENGTH];
    struct Song *next; 
};

// Function prototypes
struct Song* createSong(const char *name);
void addSong(struct Song **head, const char *name);
void playNextSong(struct Song **currentSong);
void displayCurrentSong(struct Song *currentSong);

int main() {
    struct Song *playlist = NULL;
    struct Song *currentSong = NULL;

    // Adding songs to the playlist
    addSong(&playlist, "Song A");
    addSong(&playlist, "Song B");
    addSong(&playlist, "Song C");

    // Setting the current song to the first song
    currentSong = playlist;

    // Simulating song navigation
    for (int i = 0; i < 5; i++) { 
        displayCurrentSong(currentSong);
        playNextSong(&currentSong);
    }

    return 0;
}

// Function to create a new song
struct Song* createSong(const char *name) {
    struct Song *newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;
    return newSong;
}

// Function to add a song to the playlist
void addSong(struct Song **head, const char *name) {
    struct Song *newSong = createSong(name);
    if (*head == NULL) {
        *head = newSong;
        newSong->next = *head; 
    } else {
        struct Song *temp = *head;
        while (temp->next != *head) {
            temp = temp->next; 
        }
        temp->next = newSong;
        newSong->next = *head; 
    }
}

// Function to play the next song
void playNextSong(struct Song **currentSong) {
    if (*currentSong != NULL) {
        *currentSong = (*currentSong)->next; 
    }
}

// Function to display the currently playing song
void displayCurrentSong(struct Song *currentSong) {
    if (currentSong != NULL) {
        printf("Current Song: %s\n", currentSong->name);
    }
}
