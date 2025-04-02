#include <iostream>
using namespace std;
class Graph {
public:
    int g[100][100];       
    int distance[100];     
    bool visited[100];     
    int n;                
    Graph(int matrix[100][100], int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = matrix[i][j];
            }
            distance[i] = 999;  
            visited[i] = false;
        }
    }

    void dijkstra(int src) {
        distance[src] = 0; 

        for (int count = 0; count < n - 1; count++) {
            int minDist = 999, current = -1;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && distance[i] < minDist) {
                    minDist = distance[i];
                    current = i;
                }
            }

            if (current == -1) break; // No reachable nodes left
            visited[current] = true;

            // Update distances of adjacent nodes
            for(int j=0;j<n;j++){
                if(!visited[j] && g[current][j]!=999 && distance[current]+g[current][j]<distance[j])
                {
                    distance[j] =distance[current]+g[current][j];
                }
            }
        }

        cout<<"Shortest distances from source vertex "<<src<<":\n";
        for(int i=0;i<n;i++) 
        {
            cout<<"vertex"<<i<<"-> distance:"<<distance[i]<<endl;
        }
    }
};

int main()
{
    int n,src;
    cout<<"Enter number of vertices: ";
    cin>>n;

    int matrix[100][100];
    cout<<"Enter adjacency matrix\n";
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) 
        {
            cin>>matrix[i][j];
        }
    }

    Graph obj(matrix,n);

    cout<<"Enter source vertex: ";
    cin>>src;
    obj.dijkstra(src);
    return 0;
}