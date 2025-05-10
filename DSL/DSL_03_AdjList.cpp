#include<iostream>
using namespace std;
struct Node{
    string city_name;
    int cost;
    Node* next;
    Node(string city,int c){
        city_name= city;
        cost=c;
        next=nullptr;
    }
};

class Graph{
    public:
    Node* arr[100];
    string cities[100];
    int vertices,edges;
    Graph(int v,int e){
        vertices=v;
        edges=e;
        for(int i=0;i<v;i++){
            arr[i]=nullptr;
        }
    }

    void addEdge(string src,string dest,int cost)
    {
        int srcIndex = getCityIndex(src);
        int destIndex =getCityIndex(dest);

        if(srcIndex==-1 || destIndex==-1){
            cout<<"invallid city name...."<<endl;
            return;
        }

        Node* newNode =  new Node(dest,cost);
        newNode->next =arr[srcIndex];
        arr[srcIndex] =newNode;

        newNode =  new Node(src,cost);
        newNode->next =arr[destIndex];
        arr[destIndex] =newNode;
    }

    int getCityIndex(string name)
    {
        for(int i=0;i<vertices;i++)
        {
        if(cities[i]==name){
                return i;
            }
        }
        return -1;
    }

    void addCity(){
        for(int i=0;i<vertices;i++) {
            string name;
            cout<<"Enter name of city "<<i<<":";
            cin>>name;
            cities[i]=name;
        }
    }

    void display(){
        cout<<"Adjacancy list :>"<<endl;
        for(int i=0;i<vertices;i++){
            cout<<cities[i]<<"-> ";
            Node* temp = arr[i];

            while(temp!=nullptr){
                cout<<temp->city_name<<","<<temp->cost<<"-> ";
                temp= temp->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    int v,e;
    string src,dest;
    int weight;
    cout<<"ENter no of cities :> "<<endl;
    cin>>v;
    cout<<"Enter no of edges :>"<<endl;
    cin>>e;
    Graph g(v,e);

    g.addCity();

    for(int i=0;i<v;i++)
    {
        cout<<"enter src cityy :>"<<endl;
        cin>>src;
        cout<<"enter destination cityy :>"<<endl;
        cin>>dest;
        cout<<"enter weight of edge :>"<<endl;
        cin>>weight;
        g.addEdge(src,dest,weight);
    }

    g.display();
    return 0;
}
