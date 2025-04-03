#include<iostream>
using namespace std;
class Graph{
    public:
    int v,e;
    int g[100][100];
    string cities[100];
    Graph(int v,int e){
        this->v =v;
        this->e = e;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                g[i][j] = 0;
            }
        }
    }

    void addCities(string cities[]){
        for(int i=0;i<v;i++){
            this->cities[i] = cities[i];
        }
    }

    void addEdge(string src,string dest,int weight){
        int srcIndex = getIndex(src);
        int destIndex = getIndex(dest);

        if(srcIndex==-1 || destIndex==-1){
            cout<<"invalid city.."<<endl;
            return;
        }
        //undirected
        g[srcIndex][destIndex] = weight; 
        g[destIndex][srcIndex] = weight; 
    }

    int getIndex(string city){
        for(int i=0;i<v;i++){
            if(cities[i]==city){
                return i;
            }
        }
        return -1;
    }

    void display(){
        cout<<"\n";
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};
int main(){
    int v,e;
    cout<<"enter no of cities and roads"<<endl;
    cin>>v>>e;
    Graph g(v,e);
string src,dest;
    int distance;
    string cities[v];

    cout<<"enter "<<v<<" cities"<<endl;
    for(int i=0;i<v;i++){
            cin>>cities[i];
    }
    g.addCities(cities);
    cout<<"enter src,dest,distance"<<endl;
    for(int i=0;i<v;i++){
            cin>>src>>dest>>distance;
            g.addEdge(src,dest,distance);
    }
    g.display();
    return 0;
}