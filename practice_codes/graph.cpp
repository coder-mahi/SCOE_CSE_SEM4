#include <iostream>
using namespace std;
struct Node 
{
    int vertex;
    Node* next;
};

struct Graph
{
    int V;
    Node** adjList; //array of pointer
    Graph(int V)
    {
        this->V = V; //no of vertices
        adjList = new Node*[V];  
        for(int i=0; i<V;i++)
            adjList[i] =nullptr; 
    }

    void addEdge(int u,int v)
    {
        Node* newNode =new Node{v,adjList[u]};
        adjList[u] = newNode;
        newNode =new Node{u,adjList[v]};
        adjList[v] =newNode;
    }

    void printGraph()
    {
        for(int i = 0; i < V; i++) {
            cout<<"Vertex "<<i<<" ->";
            Node* temp= adjList[i];
            while(temp!=nullptr){
                cout<<temp->vertex<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(5); 
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.printGraph();  
    return 0;
}
