#include <stdio.h>
#include <string.h>

void bubbleSort(char str[], int n) {
    char temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                // Swap characters
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);

    bubbleSort(str, n);

    printf("Sorted string: %s\n", str);

    return 0;
}