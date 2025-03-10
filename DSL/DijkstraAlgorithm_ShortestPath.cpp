#include <iostream>
using namespace std;

#define INF 9999999  

int minDistance(int dist[], bool visited[], int V) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(int graph[10][10], int V, int src) {
    int dist[10], parent[10];
    bool visited[10];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;
    parent[src] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << i << " " << dist[i] << endl;
}
int main() {
    int V, graph[10][10], src;
    
    cin >> V;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    cin >> src;
    dijkstra(graph, V, src);

    return 0;
}
