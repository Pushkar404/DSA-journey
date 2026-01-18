#include <stdio.h>

// Function to insert an element at a given position
void insertAt(int arr[], int *size, int item, int pos) {
    if(pos < 1 || pos > (*size + 1)) {
        printf("Invalid position!\n");
        return;
    }
    // Shift elements to the right
    for(int i = *size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = item; // Insert element
    (*size)++;
}

// Function to print the array
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50}; // given array
    int size = 5; // current number of elements
    int item, pos;

    printf("Enter item to insert and position (1 to %d): ", size + 1);
    scanf("%d %d", &item, &pos);

    printArray(arr, size);
    insertAt(arr, &size, item, pos);
    printArray(arr, size);

    return 0;
}
