#include<iostream>
using namespace std;
void prims(int cost[][10],int v)
{
    int edgeCount = 0;
    int minCost = 0;
    bool visited[10] ={false};

    while(edgeCount<v-1){
        int INF = 99;
        int min = INF;
        int x = -1;
        int y = -1;
        visited[0] = true;

        for(int i=0;i<v;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<v;j++)
                {
                    if(!visited[j] && cost[i][j]<min){
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if(x!=-1 && y!=-1){
            visited[y] = true;
            cout<<"edge("<<x<<","<<y<<") with weight :> "<<min<<endl;
            minCost = minCost + min;
            edgeCount++;
        }
    }
    cout<<"Total weight of MST : "<<minCost<<endl;
}
int main(){
    int v;
    cin>>v;
    int cost[10][10];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
        {
            cin>>cost[i][j];
        }
    }
    prims(cost,v);
    return 0;
}