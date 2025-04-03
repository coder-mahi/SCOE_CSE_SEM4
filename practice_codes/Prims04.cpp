#include<iostream>
using namespace std;
void prims(int cost[][10],string cities[],int v){
    int mincost = 0;
    int edgecount = 0;
    bool visited[10] = {false};
    visited[0] = true;

    while(edgecount<v-1){
        int INF = 999;
        int min = INF;
        int x = -1;
        int y = -1;

        for(int i=0;i<v;i++){
            if(visited[i]){
                for(int j=0;j<v;j++){
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
            cout<<"City("<<cities[x]<<","<<cities[y]<<") having min distance ->"<<min<<endl;
            mincost= mincost+min;
            edgecount++;
        }
    }
    cout<<"Total min weight of MST :> "<<mincost<<endl;
}
int main(){
    int v;
    cin>>v;
    int matrix[10][10];
    string cities[10];
    cout<<"Enter "<<v<<" cities :>"<<endl;
    for(int i=0;i<v;i++){
        cin>>cities[i];
    }
    cout<<"enter adjacency matrix of graph"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]==0){
                matrix[i][j] = 999;
            }
        }
    }
    prims(matrix,cities,v);
    return 0;
}