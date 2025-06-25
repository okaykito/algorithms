#include <stdio.h>

#define MAX 10
#define INF 999

void floydWarshall(int dist[MAX][MAX], int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    int n, dist[MAX][MAX];

    printf("Floyd-Warshall Algorithm - All Pairs Shortest Path\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge, INF=999):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &dist[i][j]);
            if (i != j && dist[i][j] == 0)
                dist[i][j] = INF;
        }
    }

    floydWarshall(dist, n);

    printf("\nShortest paths between every pair of nodes:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                printf("Shortest path from %d to %d: %d\n", i, j, dist[i][j]);
        }
    }

    return 0;
}
