#include <iostream>
using namespace std;

void prim(int cost[][10], int v) {
    int mincost = 0;
    int edgeCount = 0;
    bool visited[10] ={false};
    visited[0] =true; // Start from the first vertex

    while(edgeCount < v-1){
        int INF =99;
        int min = INF;
        int x= -1;
        int y =-1;

        for(int i=0; i<v; i++){
            if(visited[i]){
                for(int j = 0; j < v; j++){
                    if(!visited[j] && cost[i][j] < min){
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if(x!=-1 && y!=-1)
        {
            visited[y] = true;
            cout<<"Edge (" <<x<<", "<<y<<") with cost " <<min<<endl;
            mincost = mincost +min;
            edgeCount++;
        }
    }

    cout<<"Total cost of Minimum Spanning Tree: "<<mincost<<endl;
}

int main()
{
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    int cost[10][10];
    cout<<"Enter the cost adjacency matrix:"<<endl;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cin>>cost[i][j];
         }
    }
    prim(cost,v);
    return 0;
}