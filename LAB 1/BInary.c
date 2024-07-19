#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[mid] == x) {
            return mid;
        }

        // If x is greater, ignore left half
        if (arr[mid] < x) {
            l = mid + 1;
        }
        // If x is smaller, ignore right half
        else {
            r = mid - 1;
        }
    }

    // If the element is not present in the array
    return -1;
}

int main() {
    int n, x;

    // Get the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Get the elements of the array
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the element to be searched
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, x);

    // Print the result
    if (result != -1) {
        printf("Element %d is present at index %d.\n", x, result);
    } else {
        printf("Element %d is not present in the array.\n", x);
    }

    return 0;
}
