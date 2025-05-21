#include <stdio.h>

void topologicalSort(int graph[20][20], int n) {
    int order[20];           // Stores the topological order
    int indegree[20] = {0};  // Stores indegree of each node
    int visited[20] = {0};   // Marks visited nodes
    int stack[20];           // Stack for nodes with indegree 0
    int top = -1;            // Stack top
    int index = 0;           // Index for topological order

    // Step 1: Calculate indegree of each node
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Push all nodes with indegree 0 to stack
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            stack[++top] = i;
            visited[i] = 1;
        }
    }

    // Step 3: Process the stack
    while (top >= 0) {
        int node = stack[top--];
        order[index++] = node;

        for (int j = 1; j <= n; j++) {
            if (graph[node][j] == 1 && !visited[j]) {
                indegree[j]--;

                if (indegree[j] == 0) {
                    stack[++top] = j;
                    visited[j] = 1;
                }
            }
        }
    }

    // Step 4: Output the topological order
    printf("\nTopological Order: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", order[i]);
    }
    printf("\n");
}

int main() {
    int n, graph[20][20];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(graph, n);

    return 0;
}
