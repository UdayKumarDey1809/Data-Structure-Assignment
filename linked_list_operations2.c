#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtLocation(struct Node** head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void searchNode(struct Node* head, int key) {
    int position = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Item %d found at position %d.\n", key, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("Item %d not found in the list.\n", key);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List elements: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, position, key;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at location\n");
        printf("2. Search for a node item\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtLocation(&head, value, position);
                break;
            case 2:
                printf("Enter item to search: ");
                scanf("%d", &key);
                searchNode(head, key);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}