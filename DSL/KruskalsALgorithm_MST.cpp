#include <iostream>
using namespace std;

class Kruskal {
    int INT = 99;
    int* p;

public:
    Kruskal(int v) {
        p = new int[v];
        for (int i = 0; i < v; i++) {
            p[i] = i;
        }
    }

    ~Kruskal() {
        delete[] p;
    }

    int find(int i) {
        while (p[i] != i) {
            i = p[i];
        }
        return i;
    }

    void unionSets(int i, int j) {
        int a = find(i);
        int b = find(j);
        p[a] = b;
    }

    void kruskalMST(int cost[][10], int v) {
        int mincost = 0;

        for (int edge = 0; edge < v - 1; edge++) {
            int min = INT, a = -1, b = -1;
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    if (find(i) != find(j) && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }

            unionSets(a, b);
            cout << "Edge " << a << " - " << b << " : cost = " << min << endl;
            mincost += min;
        }

        cout << "Minimum cost of spanning tree = " << mincost << endl;
    }
};

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    int cost[10][10];
    cout << "Enter the cost adjacency matrix:" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> cost[i][j];
        }
    }

    Kruskal kruskal(v);
    kruskal.kruskalMST(cost, v);

    return 0;
}