#include<iostream>
using namespace std;
#define INF 999
class Graph{
    public:
    int V,edges;
    int distance[10];
    bool visited[10];
    Graph(int v){
        this->V = v;
        for(int i=0;i<V;i++){
            distance[i] = INF;
            visited[i] = false;
        }
    }

    void dijkstra(int g[][10],int src){
        distance[src] = 0;
        for(int count=0;count<V-1;count++){
            int min = INF;
            int minIndex = -1;
            for(int i=0;i<V;i++){
                if(!visited[i] && distance[i]<min){
                    min = distance[i];
                    minIndex = i;
                }
            }


            int current = minIndex;
            visited[current] = true;
            for(int v=0;v<V;v++){
                if(g[current][v] && !visited[v] && distance[current]+g[current][v] < distance[v]){
                    distance[v] = distance[current]+g[current][v];
                }
            }
        }
        
        cout<<"Shortest path from : "<<src<<endl;
        for(int i=0;i<V;i++){
            cout<<i<<" ->"<<distance[i]<<endl;
        }
    }
};
int main(){
    int v = 6;
    int src = 0;
    int g[10][10]={
        {0,2,5,0,3,0},
        {2,0,0,8,5,0},
        {5,0,0,0,0,6},
        {0,8,0,0,0,3},
        {3,5,0,0,0,6},
        {0,0,6,3,6,0}
    };
    Graph obj(v);
    obj.dijkstra(g,src);
    return 0;
}