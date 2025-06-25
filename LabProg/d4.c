#include <stdio.h>
#define INF 999

int main() {
    int graph[10][10];
    int visited[10];
    int distance[10];
    int min, u, source, n;

    printf("Enter No\n");
    scanf("%d",&n);
    printf("Enter Adjacency Matrix\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d",&graph[i][j]);
            if(graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    printf("Enter Source\n");
    scanf("%d",&source);

    for(int i = 1; i <= n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }
    distance[source] = 0;
    visited[source] = 1;

    for(int count = 1; count < n; count++) {
        min = INF;

        for(int i = 1; i <= n; i++) {
            if(!visited[i] && distance[i] > min) {
                min = distance[i];
                u = i;
            }
        }
        visited[u] = 1;

        for(int i = 1; i <= n; i++) {
            if(!visted[i] && distance[i] > distance[u] + graph[u][i]) {
                distance[i] = distance[u] + graph[u][i];
            }
        }
    
    }


    printf("Shortest Distance from Source node is\n");
    for(int i = 1; i<= n; i++) {
        printf("%d -> %d is %d", source, i, distance[i]);
    }
}