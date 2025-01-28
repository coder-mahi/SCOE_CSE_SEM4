#include<iostream>
struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}*head,*temp,*indexx;

int main(){
    int c,ch;
    head = nullptr;
    do{
        cout<<"Choose Option :>"<<endl;
        cout<<"1.insert"<<endl;
        cout<<"2.delete"<<endl;
        cout<<"3.display"<<endl;
        cin>>ch;
        switch (ch){
        case 1:
            int x,pos,count = 0;
            cout<<"Enter data and At which pos you want to insert ? "<<endl;
            cin>>x;
            cin>>pos;
            temp = new Node(x);
            if(head==nullptr){
                head->next = temp;
            }else{
            indexx = head;
            while(indexx->next!=nullptr){
                if(count==pos){
                    break;
                }
                indexx = indexx->next;
                count++;
            }
            Node *temp2 = indexx;
            indexx->next = temp;
            temp2->next = indexx;
            indexx->prev = temp2;
            }
            
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            cout<<""<<endl;
            break;
        }
        cout<<"Do you want to continue ? if yes 1"<<endl;
        cin>>c;
    }while(c==1);
    return 0;
}