#include<iostream>
#include<vector>
using namespace std;
class MinHeap{
    private:
        vector<int> heap;
        int parent(int i){
            return (i-1)/2;
        }
        void heapifyUp(int index){
            while(index>0 && heap[parent(index)] > heap[index]) {
                swap(heap[parent(index)],heap[index]);
                index = parent(index);
            }
        }

        public:
            void insert(int val){
                heap.push_back(val);
                heapifyUp(heap.size()-1);
            }
            int getMin(){
                return heap[0];
            }

            void display(){
                for(int i:heap){
                    cout<<i<<endl;
                }
            }
};
int main(){
    MinHeap minheap;
    minheap.insert(50);
    minheap.insert(40);
    minheap.insert(10);
    minheap.insert(60);
    minheap.insert(50);
    minheap.display();
    cout<<"ROOT OF MIN HEAP :> "<<minheap.getMin();
    return 0;
}