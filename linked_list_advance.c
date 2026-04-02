#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player {
    char name[50];
    char team[50];
    float battingAverage;
    struct Player* next;
};

struct Player* createNode(char name[], char team[], float avg) {
    struct Player* newNode = (struct Player*)malloc(sizeof(struct Player));
    strcpy(newNode->name, name);
    strcpy(newNode->team, team);
    newNode->battingAverage = avg;
    newNode->next = NULL;
    return newNode;
}

void appendPlayer(struct Player** head, char name[], char team[], float avg) {
    struct Player* newNode = createNode(name, team, avg);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Player* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayPlayers(struct Player* head) {
    int found = 0;
    printf("\nPlayers with batting average >= 50:\n");
    while (head != NULL) {
        if (head->battingAverage >= 50) {
            printf("Name: %s, Team: %s, Batting Average: %.2f\n",
                   head->name, head->team, head->battingAverage);
            found = 1;
        }
        head = head->next;
    }
    if (!found) {
        printf("No players found with batting average >= 50.\n");
    }
}

int main() {
    struct Player* head = NULL;
    int n;
    char name[50], team[50];
    float avg;

    printf("Enter number of players: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of player %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", name);
        printf("Team: ");
        scanf("%s", team);
        printf("Batting Average: ");
        scanf("%f", &avg);

        appendPlayer(&head, name, team, avg);
    }

    displayPlayers(head);

    return 0;
}