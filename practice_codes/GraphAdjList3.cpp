#include<iostream>
using namespace std;
struct GraphNode{
    string city;
    int weight;
    GraphNode* next;
    GraphNode(string city,int weight){
        this->city = city;
        this->weight = weight;
        next = nullptr;
    }
};
class Graph{
    public:
    int v,e;
    string cities[100];
    GraphNode* arr[100];
    Graph(int v,int e){
        this->v = v;
        this->e = e;

        for(int i=0;i<v;i++){
            arr[i] = nullptr;
        }
    }

    void addCities(string cities[]){
        for(int i=0;i<v;i++){
            this->cities[i] = cities[i];
        }
    }

    void addEdge(string src,string dest, int weight){
        int srcIndex= getIndex(src);
        int destIndex= getIndex(dest);

        if(srcIndex==-1 || destIndex==-1){
            cout<<"Invalid city name ?"<<endl;
            return;
        }

        GraphNode* newNode = new GraphNode(dest,weight);
        newNode->next = arr[srcIndex];
        arr[srcIndex] = newNode;

        newNode = new GraphNode(src,weight);
        newNode->next = arr[destIndex];
        arr[destIndex] = newNode;
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
        for(int i=0;i<v;i++){
           cout<<cities[i]<<" -> "<<endl;
            GraphNode* temp = arr[i];
            while(temp!=nullptr){
                cout<<temp->city<<" ";
                temp=temp->next;
            }
        }
    }
};
int main(){
    int v,e;
    cout<<"enter no of cities and roads"<<endl;
    cin>>v>>e;
    string src,dest;
    int distance;
    string cities[v];

    Graph g(v,e);
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