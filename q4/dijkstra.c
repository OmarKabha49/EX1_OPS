#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int to, weight;
} Edge;

typedef struct {
    Edge *edges;
    int size, capacity;
} AdjList;

void addEdge(AdjList *list, int to, int weight) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->edges = realloc(list->edges, list->capacity * sizeof(Edge));
    }
    list->edges[list->size].to = to;
    list->edges[list->size].weight = weight;
    list->size++;
}

// Function to perform Dijkstra's algorithm
void dijkstra(int V, AdjList *graph, int src) {
    int dist[V];
    int visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;   // Initialize all distances as infinite
        visited[i] = 0;  // Mark all vertices as unvisited
    }

    dist[src] = 0;  // Distance to the source is 0

    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum distance
        int min = INF, u = -1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min)
                min = dist[v], u = v;

        if (u == -1) break; // All remaining vertices are inaccessible

        visited[u] = 1;  // Mark the vertex as visited

        // Update distances for adjacent vertices
        for (int i = 0; i < graph[u].size; i++) {
            Edge edge = graph[u].edges[i];
            int v = edge.to;
            int weight = edge.weight;
            if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Print the results
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Function to validate the graph (no negative weights)
int isValidGraph(int V, AdjList *graph) {
    for (int u = 0; u < V; u++) {
        for (int i = 0; i < graph[u].size; i++) {
            Edge edge = graph[u].edges[i];
            if (edge.weight < 0) return 0;
        }
    }
    return 1;
}

int main() {
    int V, E;
    while (1) {
        printf("Enter number of vertices and edges: ");
        if (scanf("%d %d", &V, &E) != 2) break;

        // Allocate memory for the graph
        AdjList *graph = (AdjList *)malloc(V * sizeof(AdjList));
        for (int i = 0; i < V; i++) {
            graph[i].edges = (Edge *)malloc(1 * sizeof(Edge));
            graph[i].size = 0;
            graph[i].capacity = 1;
        }

        printf("Enter edges (u v w):\n");
        int validInput = 1;
        for (int i = 0; i < E; i++) {
            int u, v, w;
            if (scanf("%d %d %d", &u, &v, &w) != 3) {
                printf("Invalid input\n");
                validInput = 0;
                break;
            }
            if (u >= V || v >= V) {
                printf("Invalid edge\n");
                validInput = 0;
                break;
            }
            addEdge(&graph[u], v, w);
        }

        if (!validInput) {
            for (int i = 0; i < V; i++) free(graph[i].edges);
            free(graph);
            continue;
        }

        // Validate the graph
        if (!isValidGraph(V, graph)) {
            printf("Graph contains negative weights\n");
            for (int i = 0; i < V; i++) free(graph[i].edges);
            free(graph);
            continue;
        }

        int src;
        printf("Enter source vertex: ");
        if (scanf("%d", &src) != 1 || src >= V) {
            printf("Invalid source vertex\n");
            for (int i = 0; i < V; i++) free(graph[i].edges);
            free(graph);
            continue;
        }

        // Run Dijkstra's algorithm
        dijkstra(V, graph, src);

        // Free allocated memory
        for (int i = 0; i < V; i++) free(graph[i].edges);
        free(graph);
    }

    return 0;
}

