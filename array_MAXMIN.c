#include <stdio.h>
void inputArray(int arr[], int size) {
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

int MAX(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int MIN(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[10];

    // Input numbers into the array
    inputArray(arr, 10);

    // Find and display maximum and minimum
    printf("Largest element = %d\n", MAX(arr, 10));
    printf("Smallest element = %d\n", MIN(arr, 10));

    return 0;
}