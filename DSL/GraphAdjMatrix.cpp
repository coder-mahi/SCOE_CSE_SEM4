#include<iostream>
using namespace std;
struct Node {
    int dest;
    int cost;
    Node* next;
};

class Graph {
public:
    int v, e;
    int matrix[100][100];
    Node* adjList[100]; 
    Graph(int v, int e) {
        this->v = v;
        this->e = e;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                matrix[i][j] = 0;
            }
            adjList[i] = nullptr; 
        }
    }

    void addEdge(int src, int dest, int cost) {
        matrix[src][dest] = cost;
        matrix[dest][src] = cost;

        // Add edge --adjacency list
        Node* newNode = new Node();
        newNode->dest = dest;
        newNode->cost = cost;
        newNode->next = adjList[src];
        adjList[src] = newNode;

        newNode = new Node();
        newNode->dest = src;
        newNode->cost = cost;
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }

    //display adjacency matrix
    void displayMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // disply adjacency list
    void displayList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < v; i++) {
            cout << "City " << i << " -> ";
            Node* temp = adjList[i];
            while (temp != nullptr) {
                cout << "(" << temp->dest << ", " << temp->cost << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter no. of vertices: ";
    cin >> vertices;
    cout << "Enter no. of edges: ";
    cin >> edges;

    Graph g(vertices, edges);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);

    g.displayMatrix();
    g.displayList();

    return 0;
}