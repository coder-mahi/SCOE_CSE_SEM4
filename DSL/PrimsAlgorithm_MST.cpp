#include <iostream>
using namespace std;

void prim(int cost[][10], int v) {
    int mincost = 0;
    int edgeCount = 0;
    bool visited[10] = {false};
    visited[0] = true; // Start from the first vertex

    while (edgeCount < v - 1) {
        int INF = 99;
        int min = INF;
        int x = -1;
        int y = -1;

        for (int p = 0; p < v; p++) {
            if (visited[p]) {
                for (int q = 0; q < v; q++) {
                    if (!visited[q] && cost[p][q] < min) {
                        min = cost[p][q];
                        x = p;
                        y = q;
                    }
                }
            }
        }

        if (x != -1 && y != -1) {
            visited[y] = true;
            cout << "Edge (" << x << ", " << y << ") with cost " << min << endl;
            mincost += min;
            edgeCount++;
        }
    }

    cout << "Total cost of Minimum Spanning Tree: " << mincost << endl;
}

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    int cost[10][10];
    cout << "Enter the cost adjacency matrix:" << endl;
    for (int p = 0; p < v; p++) {
        for (int q = 0; q < v; q++) {
            cin >> cost[p][q];
        }
    }

    prim(cost, v);

    return 0;
}