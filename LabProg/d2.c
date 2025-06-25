#include <stdio.h>
#include <time.h>

#define INF 999

int main() {
    int n, a[20][20], i, j, min, u, v, s[20], d[20], k;

    printf("Dijkstra's Algorithm - Shortest Paths from a Source\n");
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge, non-zero for edge weight):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0 && i != j)
                a[i][j] = INF;
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &v);

    for (i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = a[v][i];
    }

    d[v] = 0;
    s[v] = 1;

    for (k = 2; k <= n; k++) {
        min = INF;
        for (i = 1; i <= n; i++) {
            if (!s[i] && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        s[u] = 1;

        for (i = 1; i <= n; i++) {
            if (!s[i] && d[i] > d[u] + a[u][i]) {
                d[i] = d[u] + a[u][i];
            }
        }
    }
    
    printf("\nShortest distances from vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        printf("%d → %d = %d\n", v, i, d[i]);
    }
    return 0;
}
