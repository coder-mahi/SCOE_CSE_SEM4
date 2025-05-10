#include<iostream>
using namespace std;
#define SIZE 10
int table[SIZE];
int hashFunction(int key){
    return key % SIZE;
}
void insert(){
    int data;
    cout<<"Enter data :> "<<endl;
    cin>>data;
    int index = hashFunction(data);
    int i=0;
    while(i<SIZE){
        int probeIndex = (index+i*i)%SIZE;//quadratic probing
        if(table[probeIndex]==0){
            table[probeIndex] = data;
            cout<<"inserted succesfully..!"<<endl;
            return;
        }
        i++;
    }
    cout<<"Table is get full..!"<<endl;
}
void display(){
    cout<<"Hash Table"<<endl;
    for(int i=0;i<SIZE;i++){
        if(table[i]!=0){
            cout<<i<<" : "<<table[i]<<endl;
        }else{
        cout<<i<<" : emptyy"<<endl;
        }
    }
}
int main(){
     int ch;
    do{
        cout<<"\n1.Insert\n2.Display record"<<endl;
        cout<<"Enter choice :"<<endl;
        cin>>ch;
    switch(ch){
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
    }
}
    while(ch<=2);
    return 0;
}