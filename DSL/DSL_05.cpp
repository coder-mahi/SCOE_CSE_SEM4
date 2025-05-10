#include<iostream>
#define INF 999
using namespace std;
class Graph 
{
public:
    int V;
    int distance[10];
    bool visited[10];

    Graph(int V)
    {
        this->V = V;
        for(int i=0;i<V;i++)
        {
            distance[i]=INF;
            visited[i]=false;
        }
    }

    void dijkstra(int g[][10], int src)
    {
        distance[src] = 0;  

        for(int count=0;count<V-1;count++)
        {
            int min =INF;
            int minindex =-1;

            for(int i=0;i<V;i++){
                if(!visited[i] && distance[i] <min) 
            {
                    min =distance[i];
                    minindex =i;
                }
            }

            int current = minindex;
            visited[current]=true;

            for(int v=0;v<V;v++){
                if(g[current][v] && !visited[v] && distance[current] + g[current][v] < distance[v]) {
                    distance[v] = distance[current] + g[current][v];
                }
            }
        }

        cout<<"\nShortest distances from nodee "<<src<<":\n";
        for(int i=0;i<V;i++){
            cout<<"to node "<<i<<" ="<<distance[i]<<endl;
        }
    }
};

int main() {
    int v,src,g[10][10];
    cout<<"Enter number of vertices: ";
    cin>>v;

    cout<<"Enter adjacency matrix:\n";
    for(int i=0;i<v;i++){
        for (int j = 0; j<v; j++) {
            cin>>g[i][j];
            if(g[i][j]==0){
                g[i][j] = 999;
            }
        }
    }

    cout<<"Enter source node: ";
    cin>>src;

    Graph obj(v);
    obj.dijkstra(g, src);

    return 0;
}
