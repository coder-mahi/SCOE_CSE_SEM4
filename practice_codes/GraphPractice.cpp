#include <iostream>
#include <vector>
using namespace std;
struct Graph {
    int V; 
    vector<vector<int>> adjList; 
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void displayGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    int vertices = 5;
    Graph g(vertices); 
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    cout << "Graph Representation (Adjacency List):\n";
    g.displayGraph();
    return 0;
}
