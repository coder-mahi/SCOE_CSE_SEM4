/*  Adjacency List representation
             10------20-----30           10 -> 20,50
 *           |     /        |           20 -> 10,50,30
 *           |   /          |           50 -> 10,20
 *           | /            |           30 -> 20,40
 *          50              40          40 -> 30
 */
#include<iostream>
#include<vector>
using namespace std;
class Edge{
    public:
    int src,dest;
    Edge(int src,int dest){
        this->src = src;
        this->dest = dest;
    }
};

void createGraph(vector<Edge> graph[], int v){
        graph[0].push_back(Edge(10, 20));
        graph[0].push_back(Edge(10, 50));

        graph[1].push_back(Edge(20, 10));
        graph[1].push_back(Edge(20, 50));
        graph[1].push_back(Edge(20, 30));

        graph[2].push_back(Edge(50, 10));
        graph[2].push_back(Edge(50, 20));

        graph[3].push_back(Edge(30, 20));
        graph[3].push_back(Edge(30, 40));

        graph[4].push_back(Edge(40, 30));
}

void display(vector<Edge> graph[], int v) {
    for (int i = 0; i < v; i++) {
        cout << "Vertex " << i << ": ";
        for (int j = 0; j < graph[i].size(); j++) {  
            cout << "(" << graph[i][j].src << " -> " << graph[i][j].dest << ") ";
        }
        cout << endl;
    }
}
int main(){
    int v = 5;
    vector<Edge> graph[v];
    createGraph(graph, v);
    display(graph,v);
    return 0;
}