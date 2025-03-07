#include <iostream>

#define V 5  
#define INF 99999  

void primMST(int graph[V][V]) {
    int final[V];   // Stores selected vertices
    int start[V];   // All vertices initially
    int key[V];     // Store minimum weights
    bool inFinal[V]; // Track vertices in final[]

    // Initialize arrays
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        inFinal[i] = false;
        start[i] = i;
    }

    key[0] = 0;  // Start from vertex 0
    final[0] = -1;  

    for (int count = 0; count < V; count++) {
        // Find the minimum key vertex not yet in final[]
        int minKey = INF, u = -1;
        for (int i = 0; i < V; i++) {
            if (!inFinal[start[i]] && key[start[i]] < minKey) {
                minKey = key[start[i]];
                u = start[i];
            }
        }

        inFinal[u] = true;  // Add vertex to final[]

        // Update adjacent vertices in start[]
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inFinal[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                final[v] = u;
            }
        }
    }

    // Print MST
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        std::cout << final[i] << " - " << i << "\t" << graph[i][final[i]] << "\n";
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    primMST(graph);

    return 0;
}
