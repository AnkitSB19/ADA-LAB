#include <stdio.h>

#define MAX 10

int graph[MAX][MAX], reach[MAX][MAX], n;

void warshall(int n);
void printMatrix(int matrix[MAX][MAX], int n);

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize the reachability matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            reach[i][j] = graph[i][j];
        }
    }

    warshall(n);

    printf("Transitive Closure Matrix:\n");
    printMatrix(reach, n);

    return 0;
}

void warshall(int n) {
    int i, j, k;

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
