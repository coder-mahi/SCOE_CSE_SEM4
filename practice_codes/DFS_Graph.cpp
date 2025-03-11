#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class GraphDFS {
    int NOV; // Number of vertices
    list<int>* adj; // Adjacency list

public:
    GraphDFS(int v) {
        NOV = v;
        adj = new list<int>[v];
    }

    void addEdge(int s, int d) {
        adj[s].push_back(d);
    }

    void DFS(int a) {
        vector<bool> vis(NOV, false);
        stack<int> stack;

        vis[a] = true;
        stack.push(a);

        while (!stack.empty()) {
            int c = stack.top();
            stack.pop();
            cout << " " << c;

            for (auto next : adj[c]) {
                if (!vis[next]) {
                    vis[next] = true;
                    stack.push(next);
                }
            }
        }
    }

    ~GraphDFS() {
        delete[] adj;
    }
};

int main() {
    int NOV, NOE;
    cout << "Enter number of vertices: ";
    cin >> NOV;
    cout << "Enter number of edges: ";
    cin >> NOE;

    GraphDFS g(NOV);

    while (NOE != 0) {
        int s, d;
        cout << "Enter source of edge: ";
        cin >> s;
        cout << "Enter destination of edge: ";
        cin >> d;

        g.addEdge(s, d);
        NOE--;
    }

    cout << "DFS start from: 0";
    g.DFS(0);

    return 0;
}