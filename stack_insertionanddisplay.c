#include <stdio.h>

#define SIZE 20 
void insert(int arr[], int *n, int element, int position) {
    if (*n >= SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    if (position < 0 || position > *n) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the right
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*n)++;  // Increase size
    printf("Inserted %d at position %d\n", element, position);
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
    int arr[SIZE];
    int n = 0;
    insert(arr, &n, 10, 0);  // Insert 10 at position 0
    insert(arr, &n, 20, 1);  // Insert 20 at position 1
    insert(arr, &n, 15, 1);  // Insert 15 at position 1

    display(arr, n);

    return 0;
}