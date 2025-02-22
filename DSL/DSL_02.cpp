/* operations on BST--
create 
search 
update 
display 
minimum salary 
maximum salary 
find avg sal
total no. of employees
delete employee */
#include<iostream>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
}*root;
int n;
void create(TreeNode* root1){
    int x;
    if(root1==nullptr){
        cout<<"Enter no. of employees you want to insert:"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            TreeNode* newNode = new TreeNode(x);
            insert(root1,newNode);
            cout<<" ->inserted successfully";
        }
    }else{
        cout<<"Employees already inserted by you.."<<endl;
    }
}
void insert(TreeNode* root1,TreeNode* newNode){
    if(root1 == nullptr){
        root1 = newNode;
        return;
    }else{
        if(newNode->data < root1->data){
            insert(root1->left,newNode);
        }else{
            insert(root1->right,newNode);
        }
    }
}
void update(TreeNode* root1){
//remaining
}
void search(TreeNode* root1){
//remaining
}
void display(TreeNode* root1){
//remaining
}
void minSalary(TreeNode* root1){
//remaining
}
void maxSalary(TreeNode* root1){
//remaining
}
void findAvgSalary(TreeNode* root1){
//remaining
}
void totalEmployees(TreeNode* root1){
//remaining
}
void deleteEmployees(TreeNode* root1){
//remaining
}
int main(){
    int ch,c;
    root = nullptr;
    do{
        cout<<"Select operation on BST -> "<<endl;
        cout<<"1.create\n2.search\n3.update\n4.display\n5.minimum salary\n6.maximum salary\n7.find avg salary\n8.total no. of employee\n9.delete employee"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                create(root);
                break;
            case 2:
                cout<<""<<endl;
                search(root);
                break;
            case 3:
                update(root);
                break;
            case 4:
                display(root);
                break;
            case 5:
                minSalary(root);
                break;
            case 6:                
                maxSalary(root);
                break;
            case 7:
                findAvgSalary(root);
                break;
            case 8:
                totalEmployees(root);
                break;
            case 9:
                deleteEmployees(root);
                break;
            default:
                cout<<"invalid choice selected..."<<endl;
        }
        cout<<"Do you want to continue??"<<endl;
        cin>>c;
    }while(c==1);
    return 0;
}

