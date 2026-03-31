#include <stdio.h>

#define SIZE 20

void delete(int arr[], int *n, int position) {
    if (*n == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    if (position < 0 || position >= *n) {
        printf("Invalid position!\n");
        return;
    }

    int deletedElement = arr[position];

    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;  // Decrease size
    printf("Deleted element %d from position %d\n", deletedElement, position);
}
void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE] = {10, 20, 30, 40, 50};  // Initial array
    int n = 5;

    display(arr, n);

    delete(arr, &n, 2);

    display(arr, n);

    delete(arr, &n, 0);

    display(arr, n);

    return 0;
}