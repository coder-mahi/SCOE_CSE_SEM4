#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class GraphBFS {
    int NOV; // Number of vertices
    list<int>* adj; // Adjacency list

public:
    GraphBFS(int v) {
        NOV = v;
        adj = new list<int>[v];
    }

    void addEdge(int s, int d) {
        adj[s].push_back(d);
    }

    void BFS(int a) {
        vector<bool> vis(NOV, false);
        queue<int> q;

        vis[a] = true;
        q.push(a);

        while (!q.empty()) {
            int c = q.front();
            q.pop();
            cout << " " << c;

            for (auto next : adj[c]) {
                if (!vis[next]) {
                    vis[next] = true;
                    q.push(next);
                }
            }
        }
    }

    ~GraphBFS() {
        delete[] adj;
    }
};

int main() {
    int NOV, NOE;
    cout << "Enter number of vertices: ";
    cin >> NOV;
    cout << "Enter number of edges: ";
    cin >> NOE;

    GraphBFS g(NOV);

    while (NOE != 0) {
        int s, d;
        cout << "Enter source of edge: ";
        cin >> s;
        cout << "Enter destination of edge: ";
        cin >> d;

        g.addEdge(s, d);
        NOE--;
    }

    cout << "BFS start from: 0";
    g.BFS(0);

    return 0;
}