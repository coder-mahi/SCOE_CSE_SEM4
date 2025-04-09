#include<iostream>
using namespace std;
#define size 10

int rolls[size];
string names[size];
int marks[size];
int count = 0;

int hashFunction(int key){
    return key%size;
}

void linearProb(int roll,string name,int mark,int i){
    int hashvalue =(hashFunction(roll)+i) %size;
    if(!rolls[hashvalue])
    {
        rolls[hashvalue] = roll;
        names[hashvalue]=name;
        marks[hashvalue] = mark;
    }else{
        i++;
        linearProb(roll,name,mark,i);
    }
}

void insert(){
    int roll;
    string name;
    int mark;
    cout<<"ENter student(rollno,name,marks)"<<endl;
    cin>>roll;
    cin>>name;
    cin>>mark;

    count = 0;
    int hashValue= hashFunction(roll);
    count = count+1;
    if(!rolls[hashValue]){
        rolls[hashValue] =roll;
        names[hashValue] = name;
        marks[hashValue] = mark;
    }else{
        linearProb(roll,name,mark,count);
    }
        
}
void update(){
    int temp;
    int cnt = 0;
    cout<<"enter roll no of student which you want to update :> "<<endl;
    cin>>temp;
    int hashvalue = hashFunction(temp);
    if(rolls[hashvalue]==temp){
        cout<<"Enter new roll,name,marks :> "<<endl;
        cin>>rolls[hashvalue];
        cin>>names[hashvalue];
        cin>>marks[hashvalue];
    }else{
        cnt = hashvalue;
        while(rolls[cnt]!=temp){
            cnt++;
        }
        cout<<"Enter new roll,name,marks :> "<<endl;
        cin>>rolls[cnt];
        cin>>names[cnt];
        cin>>marks[cnt];
    }
}
void deleteFunc(){
    int temp;
    int cnt = 0;
    cout<<"enter roll no of student which you want to delete :> "<<endl;
    cin>>temp;
    int hashvalue = hashFunction(temp);
    if(rolls[hashvalue]==temp){
        cout<<"Enter new roll,name,marks :> "<<endl;
        rolls[hashvalue] = 0;
        names[hashvalue] = "0";
        marks[hashvalue] =0;
    }else{
        cnt = hashvalue;
        while(rolls[cnt]!=temp){
            cnt++;
        }
        rolls[hashvalue] = 0;
        names[hashvalue] = "0";
        marks[hashvalue] =0;
    }
}
void display(){
    for(int i=0;i<size;i++){
        cout<<"index"<<i<<"\t"<<rolls[i]<<","<<names[i]<<","<<marks[i]<<endl;
    }
}
int main(){
    int ch;
    int n,temp;
    int roll,mark;
    string name;
    do{
        cout<<"1.insert\n2.update\n3.delete\n4.display"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                update();
                break;
            case 3:
                deleteFunc();
                break;
            case 4:
                display();
                break;
        }
    }while(ch<=4);
    return 0;
}