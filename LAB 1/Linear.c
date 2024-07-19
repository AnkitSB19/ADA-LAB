#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return the index of the element if found
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int n, x;

    // Get the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Get the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the element to be searched
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    // Perform linear search
    int result = linearSearch(arr, n, x);

    // Print the result
    if (result != -1) {
        printf("Element %d is present at index %d.\n", x, result);
    } else {
        printf("Element %d is not present in the array.\n", x);
    }

    return 0;
}
