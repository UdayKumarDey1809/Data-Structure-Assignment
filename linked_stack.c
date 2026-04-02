#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto stack.\n", value);
}

void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty. Nothing to pop.\n");
        return;
    }
    struct Node* temp = *top;
    printf("%d popped from stack.\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* top = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Linked Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                display(top);
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