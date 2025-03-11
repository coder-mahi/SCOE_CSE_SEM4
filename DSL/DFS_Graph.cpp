#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS
void dfs(int node, vector<bool>& visited, vector<vector<int>>& adjList) {
    // Mark the current node as visited
    visited[node] = true;
    
    // Process the current node (print or do other operations)
    cout << node << " ";

    // Explore all unvisited neighbors
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adjList);
        }
    }
}

// Function to initialize DFS and handle disconnected components
void performDFS(int numNodes, vector<vector<int>>& adjList) {
    vector<bool> visited(numNodes + 1, false);

    // Iterate through all nodes to handle disconnected components
    for (int i = 1; i <= numNodes; ++i) {
        if (!visited[i]) {
            dfs(i, visited, adjList);
        }
    }
}

int main() {
   
    int numNodes, numEdges;
    cin >> numNodes >>  numEdges;
    vector<vector<int>> adjList(numNodes + 1);

    // Adding edges to the graph
    for(int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
       adjList[u].push_back(v);
       adjList[v].push_back(u);
    }

    // Perform DFS
    cout << "DFS traversal: ";
    performDFS(numNodes, adjList);

    return 0;
}