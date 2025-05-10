#include<iostream>
#include<vector>
using namespace std;
class MaxHeap{
    private:
        vector<int> heap;
        int parent(int i){
            return (i-1)/2;
        }
        void heapifyUp(int index){
            while(index > 0 && heap[parent(index)]<heap[index] ){
                swap(heap[parent(index)],heap[index]);
                index = parent(index);
            }
        }
    public:
        void insert(int val){
            heap.push_back(val);
            heapifyUp(heap.size()-1);
        }

        void display(){
            for(int i: heap){
                cout<<i<<" "<<endl;
            }
        }
        int getMax(){
            return heap[0];
        }
};
int main(){
    MaxHeap maxheap;
    maxheap.insert(10);
    maxheap.insert(20);
    maxheap.insert(30);
    maxheap.insert(40);
    maxheap.insert(50);

    maxheap.display();

    cout<<"ROOT of MAX HEAP :> "<<maxheap.getMax();
    return 0;
}