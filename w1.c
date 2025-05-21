#include <stdio.h>

#define MAX 10

void warshall(int reach[MAX][MAX], int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
}

int main() {
    int reach[MAX][MAX], n;

    printf("Warshall's Algorithm - Transitive Closure\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 or 1):\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &reach[i][j]);

    warshall(reach, n);

    printf("\nTransitive Closure Matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d\t", reach[i][j]);
        printf("\n");
    }

    return 0;
}
