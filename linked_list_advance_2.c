#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int ac_no;
    char name[50];
    float balance;
    struct Account* prev;
    struct Account* next;
};

struct Account* createNode(int ac_no, char name[], float balance) {
    struct Account* newNode = (struct Account*)malloc(sizeof(struct Account));
    newNode->ac_no = ac_no;
    strcpy(newNode->name, name);
    newNode->balance = balance;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Account** head, int ac_no, char name[], float balance) {
    struct Account* newNode = createNode(ac_no, name, balance);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Account* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void displayAccounts(struct Account* head) {
    if (head == NULL) {
        printf("No accounts found.\n");
        return;
    }
    printf("\nBank Account Holders:\n");
    while (head != NULL) {
        printf("Account No: %d, Name: %s, Balance: %.2f\n",
               head->ac_no, head->name, head->balance);
        head = head->next;
    }
}

float calculateTotalBalance(struct Account* head) {
    float total = 0;
    while (head != NULL) {
        total += head->balance;
        head = head->next;
    }
    return total;
}

int main() {
    struct Account* head = NULL;
    int n, ac_no;
    char name[50];
    float balance;

    printf("Enter number of bank account holders: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of account holder %d:\n", i + 1);
        printf("Account No: ");
        scanf("%d", &ac_no);
        printf("Name: ");
        scanf("%s", name);
        printf("Balance: ");
        scanf("%f", &balance);

        insertAtEnd(&head, ac_no, name, balance);
    }

    displayAccounts(head);

    float totalBalance = calculateTotalBalance(head);
    printf("\nTotal Balance of all account holders: %.2f\n", totalBalance);

    return 0;
}