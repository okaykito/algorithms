#include <stdio.h>
#include <time.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], visited[MAX];
int numVertices;

int main() {
    int ne = 1, minCost = 0;
    int u, v, a, b, min;
    clock_t start, end;

    printf("\n\tPrim's Algorithm - Minimum Spanning Tree\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the cost adjacency matrix (0 if no edge):\n");
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    start = clock();  // Start timing

    // Start with first vertex
    visited[1] = 1;

    printf("\nEdges in the Minimum Cost Spanning Tree:\n");

    while (ne < numVertices) {
        min = INF;

        for (int i = 1; i <= numVertices; i++) {
            if (visited[i]) {
                for (int j = 1; j <= numVertices; j++) {
                    if (cost[i][j] < min) {
                        if(visited[i] != 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                        }
                    }
                }
            }
        }

        visited[b] = 1;
        printf("%d) Edge (%d - %d) cost: %d\n", ne++, a, b, min);
        minCost += min;
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum total cost: %d\n", minCost);
    end = clock();

    printf("Start time is %lf\n", (double)start);
    printf("End time is %lf\n", (double)end);
    printf("Total time is %lf\n", (double)(end - start));
    return 0;
}
