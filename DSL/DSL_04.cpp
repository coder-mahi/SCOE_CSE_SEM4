/**/

#include<iostream>
using namespace std;
void prims(int distance[][10],string cities[],int v){
    int mincost = 0;
    int edgecount = 0;
    bool visited[10] = {false};
    visited[0] = true;
    
    while(edgecount<v-1){
        int infinity =99;
        int min = infinity;
        int x = -1;
        int y=-1;

        for(int i=0;i<v;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<v;j++){
                    if(!visited[j] && distance[i][j]<min){
                        min = distance[i][j];
                        x = i;
                        y =j;
                    }
                }
            }
        }
        if(x!=-1 && y!=-1){
            visited[y] = true;
            cout<<"CITIES :> ("<<cities[x]<<"<-->"<<cities[y]<<") having distance:"<<min<<endl;
            mincost=min+mincost;
            edgecount++;
        }

    }
    cout<<"total weight of mst :"<<mincost<<endl;
}
int main(){
    int v;
    int distance[10][10];
    string cities[10];

    cout<<"Enter no of cities :> "<<endl;
    cin>>v;
    cout<<"Enter name of cities :> "<<endl;
    for(int i=0;i<v;i++){
        cin>>cities[i];
    }
    cout<<"Enter adjacency matrix distaces between cities :>"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>distance[i][j];
            if(distance[i][j]==0){
                distance[i][j] = 99;
            }
        }
    }

    prims(distance,cities,v);
    return 0;
}