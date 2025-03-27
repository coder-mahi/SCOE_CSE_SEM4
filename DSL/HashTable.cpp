#include<iostream>
#include<vector>
#define size 10
using namespace std;

int arr[size];
int count = 0;

int hashFunction(int key){
    return key%size;
}

void colisionResolution(int key,int i){ 
    //linear probing --> h(x)= [h(x)+i] % size
    int hashvalue = (hashFunction(key) + i) % size;
    if(!arr[hashvalue])
    {
        arr[hashvalue] = key;
    }else{
        i++;
        colisionResolution(key,i);
    }
}

void insert(int key){
    count =0;
    int index = hashFunction(key);
    count =count +1;
    if(!arr[index])
    {
        arr[index]= key;
    }
    else{
        colisionResolution(key,count);
    }
}

void display(){
    cout<<"\t***Hash-Table**"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"index("<<i<<") "<<arr[i]<<endl;
    }
}


int main()
{
    int key;
    int arr[size];
    int ch;

    cout<<"Do you want to process further (yes 1)(no 2)"<<endl;
    cin>>ch;

    while(ch==1)
    {
        cout<<"choose operation ?"<<endl;
        cout<<"\n1.insert\n2.display"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter key :>"<<endl;
                cin>>key;
                insert(key);
                break;
            case 2:
                display();
                break;
            }
            deafult:
            cout<<"invalid choice..."<<endl;
    }

    return 0;
}