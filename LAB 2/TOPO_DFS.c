#include <stdio.h>

#define MAX 100

int s[MAX] = {0};

void dfs(int u, int n, int a[][n]) {
    s[u] = 1;
    for (int v = 0; v < n; v++) {
        if (a[u][v] && !s[v]) {
            dfs(v, n, a);
        }
    }
    printf("%d ", u);
}

void dfs_topo(int n, int a[][n]) {
    for (int u = 0; u < n; u++) {
        if (!s[u]) {
            dfs(u, n, a);
        }
    }
}

int main() {
    int n;
    int a[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Topological ordering of vertices: ");
    dfs_topo(n, a);
    printf("\n");

    return 0;
}
