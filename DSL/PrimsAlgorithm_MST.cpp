#include <iostream>
using namespace std;

#define INF 9999999  

int minKey(int key[], bool inMST[], int V) {
    int min = INF, minIndex = -1;
    for(int v=0;v<V;v++){
       if(!inMST[v] && key[v]<min){
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int graph[10][10], int V) {
    cout<<"Edge\tWeight\n";
    for(int i = 1; i < V; i++){
        cout<<parent[i]<<" - " <<i<<"\t"<<graph[i][parent[i]]<<endl;
    }
}

void primMST(int graph[10][10], int V) {
    int parent[10]; // final MST  
    int key[10];    // cost of edges
    bool inMST[10]; // check vertexx is visited or not

    for(int i=0;i<V;i++){
        key[i] =INF;
        inMST[i]= false;
    }

    key[0] = 0;    
    parent[0] = -1;  

    for(int count=0;count<V-1;count++){
       int u = minKey(key, inMST, V);
        inMST[u] = true;

        for(int v=0;v<V;v++){
            if(graph[u][v] && !inMST[v] && graph[u][v]<key[v]){
                parent[v] =u;
                key[v] =graph[u][v];
            }
        }
    }
    printMST(parent, graph, V);
}

int main() {
    int V, graph[10][10];

    cin >> V;
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++) 
            cin >> graph[i][j];

    primMST(graph, V);

    return 0;
}
