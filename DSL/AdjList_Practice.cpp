#include<iostream>
using namespace std;
struct Node{
    int data;
    int weight;
    Node* next;
    Node(int data,int weight){
        this->data=data;
        this->weight=weight;
        next=nullptr;
    }
};
class Graph{
    public:
    int vertices,edges;
    Node* arr[100];
    int vArr[100];
    Graph(int v,int e){
        vertices = v;
        edges = e;
        for (int i = 0; i < 100; i++) {
            arr[i] = nullptr;
            vArr[i] = 0;
        }
    }

    void addEdge(int src,int dest,int weight){
        int srcIndex = getIndex(vArr,src);
        int destIndex = getIndex(vArr,dest);

        if(srcIndex==-1 || destIndex==-1){
            cout<<"Vertex not found..."<<endl;
            return;
        }

        Node* newNode = new Node(dest,weight);
        newNode->next = arr[srcIndex];
        arr[srcIndex] = newNode;

        newNode = new Node(src,weight);
        newNode->next = arr[destIndex];
        arr[destIndex] = newNode;
    }

    int getIndex(int arr[],int x){
        for(int i=0;i<vertices;i++){
            if(arr[i]==x){
                return i;
            }
        }
        return -1;
    }

    void addVertex(int vertex,int index){
        vArr[index] = vertex;
    }
    
    void display(){
        for(int i=0;i<vertices;i++){
            cout<<vArr[i]<<" -> ";
            Node* temp = arr[i];

            while(temp!=nullptr){
                cout<<temp->data<<","<<temp->weight<<" -> ";
                temp= temp->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    int v,e;
    cout<<"no. of vertices :>"<<endl;
    cin>>v;
    cout<<"no. of edges :>"<<endl;
    cin>>e;
    Graph g(v,e);
    cout<<"Add vertices :> "<<v<<endl;
    for(int i=0;i<v;i++){
        int temp;
        cin>>temp;
        g.addVertex(temp,i);
    }

    cout<<"Add edges :> "<<endl;
    for(int i=0;i<v;i++){
        int src,dest,weight;
        cout<<"src vertex :> ";
        cin>>src;
        cout<<"\ndest vertex :> ";
        cin>>dest;
        cout<<"\nweight of edge:> ";
        cin>>weight;
        g.addEdge(src,dest,weight);
    }

    g.display();
    return 0;
}