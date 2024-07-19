#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool place(int x[], int k);
void printSolution(int x[], int n);
void nQueens(int n);

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nQueens(n);
    return 0;
}

// Function to solve the N-Queens problem
void nQueens(int n) {
    int x[10] = {0}; // Array to store the positions of queens
    int count = 0;   // Counter for the number of solutions
    int k = 1;       // Current column

    while (k != 0) {
        x[k] = x[k] + 1;
        
        while (x[k] <= n && !place(x, k)) {
            x[k] = x[k] + 1;
        }
        
        if (x[k] <= n) {
            if (k == n) {
                printSolution(x, n);
                printf("Solution found\n");
                count++;
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }
    
    printf("Total solutions: %d\n", count);
}

// Function to check if the queen can be placed at position x[k]
bool place(int x[], int k) {
    for (int i = 1; i < k; i++) {
        if ((x[i] == x[k]) || (i - x[i] == k - x[k]) || (i + x[i] == k + x[k])) {
            return false;
        }
    }
    return true;
}

// Function to print the solution
void printSolution(int x[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}
