#include <stdio.h>
#define MAX 10
#define INF 999

int floyd(int dist[MAX][MAX],int n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    int dist[MAX][MAX], n;
    printf("FLOYD'S\n");
    printf("Enter No of Vertices\n");
    scanf("%d",&n);
    printf("Enter Dist?\n");
    for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                scanf("%d",&dist[i][j]);
                if(i != j && dist[i][j] == 0)
                    dist[i][j] = INF;
            }
        }

    floyd(dist, n);

    for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                printf("Closest Edge between %d and %d is %d\n",i,j,dist[i][j]);

            }
            }
            }