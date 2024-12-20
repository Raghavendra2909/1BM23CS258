#include <stdio.h>
#include <stdbool.h>

#define MAX 100 // Maximum number of vertices

// Adjacency matrix to represent the graph
int graph[MAX][MAX];
bool visited[MAX]; // Array to keep track of visited vertices

// Function to perform DFS traversal
void dfs(int vertex, int n) {
    visited[vertex] = true;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

// Function to check if the graph is connected
bool isConnected(int n) {
    // Initialize visited array to false
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // Perform DFS from the first vertex
    dfs(0, n);

    // Check if all vertices are visited
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false; // If any vertex is not visited, the graph is not connected
        }
    }
    return true;
}

int main() {
    int n, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the graph with 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (u v) where u and v are vertices (0-based index):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Since the graph is undirected
    }

    if (isConnected(n)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}

// Enter the number of vertices: 4
// Enter the number of edges: 3
// Enter the edges (u v) where u and v are vertices (0-based index):
// 0 1
// 1 2
// 2 3

// The graph is connected.
