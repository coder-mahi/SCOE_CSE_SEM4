#include <iostream>
using namespace std;

struct Edge {
    int u, v, weight;
};

void sortEdges(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
    else { parent[rootY] = rootX; rank[rootX]++; }
}

void kruskalMST(Edge edges[], int V, int E) {
    int parent[10], rank[10];
    Edge result[10];
    int e = 0, i = 0;

    for (int v = 0; v < V; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    sortEdges(edges, E);

    while (e < V - 1 && i < E) {
        Edge nextEdge = edges[i++];
        int x = find(parent, nextEdge.u);
        int y = find(parent, nextEdge.v);
        if (x != y) {
            result[e++] = nextEdge;
            unionSet(parent, rank, x, y);
        }
    }

    for (i = 0; i < e; i++)
        cout << result[i].u << " - " << result[i].v << "  " << result[i].weight << endl;
}

int main() {
    int V, E;
    Edge edges[10];

    cin >> V >> E;
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    kruskalMST(edges, V, E);

    return 0;
}
