#include <stdio.h>
#include <time.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX], parent[MAX];
int numVertices;

int find(int i) {
    while(parent[i]) {
        i = parent[i];
    }
    return i;
}

int unionSet(int i, int j) {
    while (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int edgeCount = 1, minCost = 0;
    clock_t start, end;
    int u, v, a, b, min;

    printf("Kruskal bitch\n");
    printf("Number of Vertices\n");
    scanf("%d",&numVertices);
    printf("Cost\n");
    for(int i = 1; i <= numVertices; i++) {
        for(int j = 1; j <= numVertices; j++) {
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Edge of MST are");
    start = clock();

    while(edgeCount < numVertices) {
        min = INF;
        for(int i = 1; i <= numVertices; i++) {
                for(int j = 1; j <= numVertices; j++) {
                    if (cost[i][j] < min) {
                        min = cost[i][j];
                        u = a = i;
                        v = b = j;
                    }
                }
            }
            u = find(u);
            v = find(v);
            
            if(unionSet(u,v)) {
                printf("%d edge (%d,%d) = %d", edgeCount++, a, b, min);
                minCost += min;
            }

            printf("Total Cost %d", minCost);
            printf("start time %lf", (double)start);
            printf("end time %lf", (double)end);
            printf("total %lf", (double)(end - start));

    }
}