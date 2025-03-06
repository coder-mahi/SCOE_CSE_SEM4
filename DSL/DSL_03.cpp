/*
There are flight paths between cities. If there is a flight between city A and city
B then there is an edge between the cities. The cost of the edge can be the time that
flight takes to reach city B from A or the amount of fuel used for the journey. The
node can be represented by airport name or name of the city. Use adjacency list
representation of the graph and adjacency matrix representation of the graph.
Justify the storage representation used.
*/
#include <iostream>
#include <string>
using namespace std;
// Graph class
class Graph {
public:
    int v, e;
    int matrix[100][100]; // Adjacency matrix
    string cities[100];   // Array to store city names

    // Constructor
    Graph(int v, int e) {
        this->v = v;
        this->e = e;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                matrix[i][j] = 0; // Initialize adjacency matrix
            }
        }
    }

    // Function to add a city name
    void addCity(int index, string name) {
        cities[index] = name;
    }

    // Function to add an edge to the graph
    void addEdge(string src, string dest, int cost) {
        int srcIndex = getCityIndex(src);
        int destIndex = getCityIndex(dest);

        if (srcIndex == -1 || destIndex == -1) {
            cout << "Invalid city name!" << endl;
            return;
        }

        // Add edge to adjacency matrix
        matrix[srcIndex][destIndex] = cost;
        matrix[destIndex][srcIndex] = cost;
    }

    int getCityIndex(string name) {
        for (int i = 0; i < v; i++) {
            if (cities[i] == name) {
                return i;
            }
        }
        return -1;
    }

    void displayMatrix() {
        cout << "Adjacency Matrix:" << endl;
        cout << "  ";
        for (int i = 0; i < v; i++) {
            cout << cities[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < v; i++) {
            cout << cities[i] << " ";
            for (int j = 0; j < v; j++) {
                cout << matrix[i][j] << " ";
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

    // Add city names
    for (int i = 0; i < vertices; i++) {
        string name;
        cout << "Enter name of city " << i << ": ";
        cin >> name;
        g.addCity(i, name);
    }

    // Add edges with costs
    for (int i = 0; i < edges; i++) {
        string src, dest;
        int cost;
        cout << "Enter source city: ";
        cin >> src;
        cout << "Enter destination city: ";
        cin >> dest;
        cout << "Enter cost (time or fuel): ";
        cin >> cost;
        g.addEdge(src, dest, cost);
    }

    g.displayMatrix();
    return 0;
}