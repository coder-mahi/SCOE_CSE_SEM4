#include<iostream>
using namespace std;
struct GraphNode{
    int data;
    GraphNode* next;
    GraphNode(int val){
        data = val;
        next = nullptr;
    }
};
class Graph{
    public:
    void addEdge(int src, int dest,int weight){
        //working
    }
};
int main(){

    return 0;
}