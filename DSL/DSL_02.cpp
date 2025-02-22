//operations on BST given by sir
/* create 
search 
update 
display 
minimum salary 
maximum salary 
find avg sal
total no. of employees
delete employee*/
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
void create(TreeNode* root1){
    int n,x;
    if(root1==nullptr){
        cout<<"Enter no. of employees :"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            insert(root1,x);
        }
    }else{
        cout<<"Employees already inserted by you.."<<endl;
    }
}
void insert(TreeNode* root1,int x){
    TreeNode* newNode = new TreeNode(x);
    if(root1!=nullptr){
        
    }
}
void update(TreeNode* root1){

}
void search(TreeNode* root1){

}
void display(TreeNode* root1){

}
void minSalary(TreeNode* root1){

}
void maxSalary(TreeNode* root1){

}
void findAvgSalary(TreeNode* root1){

}
void totalEmployees(TreeNode* root1){

}
void deleteEmployees(TreeNode* root1){

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

