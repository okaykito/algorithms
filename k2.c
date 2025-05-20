#include <stdio.h>
#include <time.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], parent[MAX];
int numVertices;

int find(int i) {
    while (parent[i]) // p[3] = 2, i become parent[3] ~ 2; p[2] = 1, 1 = p[i]
        i = parent[i];
    return i;
}

int unionSet(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int edgeCount = 1, minCost = 0;
    int u, v, a, b, min;
    clock_t start, end;

    printf("\n\tImplementation of Kruskal's algorithm\n");
    printf("\nEnter the no. of vertices:");
    scanf("%d", &numVertices);

    printf("\nEnter the cost adjacency matrix:\n");
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");
    start = clock();

    while (edgeCount < numVertices) {
        min = INF;
        for (int i = 1; i <= numVertices; i++) {
            for (int j = 1; j <= numVertices; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (unionSet(u, v)) {
            printf("%d edge (%d,%d) =%d\n", edgeCount++, a, b, min);
            minCost += min;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\n\tMinimum cost = %d\n", minCost);
    end = clock();
    printf("Start time is %lf\n", (double)start);
    printf("End time is %lf\n", (double)end);
    printf("Total time is %lf\n", (double)(end - start));
    return 0;
}
