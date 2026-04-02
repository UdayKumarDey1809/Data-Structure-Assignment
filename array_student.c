#include <stdio.h>

struct student {
    int rollno;
    char name[50];
    int age;
};

void displayEligibleStudents(struct student s[], int n) {
    printf("\nStudents with age >= 20:\n");
    for (int i = 0; i < n; i++) {
        if (s[i].age >= 20) {
            printf("Roll No: %d\n", s[i].rollno);
            printf("Name   : %s\n", s[i].name);
            printf("Age    : %d\n\n", s[i].age);
        }
    }
}

int main() {
    struct student s[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter details of student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].rollno);
        printf("Name   : ");
        scanf("%s", s[i].name);
        printf("Age    : ");
        scanf("%d", &s[i].age);
        printf("\n");
    }

    displayEligibleStudents(s, 5);
    return 0;
}