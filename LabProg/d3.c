#include <stdio.h>

#define INF 999

int main() {
    int graph[10][10];     // graph[i][j] stores cost from i to j
    int distance[10];      // shortest known distance from source to each node
    int visited[10];       // 1 if node has been visited
    int n, source, i, j, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;  // no edge between different nodes means infinite distance
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distances and visited flags
    for (i = 1; i <= n; i++) {
        distance[i] = graph[source][i];  // initial distances from source
        visited[i] = 0;                  // mark all as unvisited
    }
    distance[source] = 0;
    visited[source] = 1;

    // Main Dijkstra logic
    for (int count = 1; count < n; count++) {
        min = INF;
        for (i = 1; i <= n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (i = 1; i <= n; i++) {
            if (!visited[i] && distance[i] > distance[u] + graph[u][i]) {
                distance[i] = distance[u] + graph[u][i];
            }
        }
    }

    // Output result
    printf("\nShortest distances from source node %d:\n", source);
    for (i = 1; i <= n; i++) {
        printf("%d --> %d = %d\n", source, i, distance[i]);
    }

    return 0;
}
