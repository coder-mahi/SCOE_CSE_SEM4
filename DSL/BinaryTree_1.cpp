// assignment no.1
#include<iostream>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
TreeNode *root = nullptr;
void preorder(TreeNode *root1){
    cout<<root1->data<<" -> ";
    preorder(root1->left);
    preorder(root1->right);
}
void inorder(TreeNode *root1){
    inorder(root1->left);
    cout<<root1->data<<" -> ";
    inorder(root1->right);
}
void postorder(TreeNode *root1){
    postorder(root1->left);
    postorder(root1->right);
    cout<<root1->data<<" -> ";
}
void insert(TreeNode *root1,TreeNode *newNode){
    if(root1 == nullptr){
        root1 = newNode;
    }else{
        char ch;
        cout<<"Where you want to insert ?(l/r)";
        cin>>ch;
        if(ch=='l'){
            if(root1->left==nullptr){
                root1->left = newNode;
            }else{
                insert(root1->left,newNode);
            }
        }else if(ch=='r'){
            if(root1->right == nullptr){
                root1->right = newNode;
            }else{
                insert(root1->right,newNode);
            }
        }
    }
}
void create(){
    int x;
    cout<<"Enter value :"<<endl;
    cin>>x;
    TreeNode *newNode = new TreeNode(x);
    if(root==nullptr){
        root = newNode;
    }else{
        insert(root,newNode);
    }
}
void display(TreeNode *root1){
    if(root1==nullptr){
        cout<<"Tree is empty"<<endl;
        return;
    }else{
        int ch;
        cout<<"1.preorder\n2.inorder\n3.postorder";
        cin>>ch;
        if(ch==1) preorder(root1);
        else if(ch==2) inorder(root1);
        else if(ch==3) postorder(root1);
    }
}
int main(){
    int ch,c;
    root = nullptr;
    do{
        cout<<"Select operation :>"<<endl;
        cout<<"1. insert"<<endl;
        cout<<"2. display"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            create();
            break;
            case 2:
            display(root);
            default:
            cout<<"select valid option..."<<endl;
        }
        cout<<"Do you want to continue ? if yes hit 1"<<endl;
        cin>>c;
    }while(c==1);
    return 0;
}