#include<iostream>
using namespace std;
#define INF 9999
class Graph{
    public:
    int V;
    int distance[10];
    bool visited[10];
    Graph(int V){
        this->V = V;
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
                    distance[v] = distance[current] + g[current][v];
                }
            }
        }

        cout<<"Shortest paths from src :"<<src<<endl;
        for(int i=0;i<V;i++){
            cout<<"To -> "<<i<<" = "<<distance[i]<<endl;
        }
    }
};
int main(){
    int V,src;
    cout<<"Enter V:>"<<endl;
    cin>>V;
    int g[10][10];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>g[i][j];
            if(g[i][j]==0){
                g[i][j]=9999;
            } 
        }
    }

    cout<<"Enter src :> "<<endl;
    cin>>src;
    Graph obj(V);
    obj.dijkstra(g,src);
    return 0;
}