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
};
TreeNode* root = nullptr;

void insert(TreeNode*& root1,TreeNode* newNode){
    if(root1==nullptr){
        root1= newNode;
        return;
    }
    char ch;
    cout<<"select (l/r) to insert newNode :>"<<endl;
    cin>>ch;
    if(ch=='l' || ch=='L'){
        insert(root1->left, newNode);
    }else if(ch=='r' || ch=='R'){
        insert(root1->right, newNode);
    }
}

void create(TreeNode*& root1){
    int x;
    cout<<"Enter value :>"<<endl;
    cin>>x;
    TreeNode* newNode = new TreeNode(x);
    if(root1==nullptr){
        root1= newNode;
        return;
    }else{
        insert(root1,newNode);
    }
}

void preorder(TreeNode* root1){
    if(root1==nullptr) return;
    cout<<root1->data<<"\t";
    preorder(root1->left);
    preorder(root1->right);
}

void inorder(TreeNode* root1){
    if(root1==nullptr) return;
    inorder(root1->left);
    cout<<root1->data<<"\t";
    inorder(root1->right);
}

void postorder(TreeNode* root1){
    if(root1==nullptr) return;
    postorder(root1->left);
    postorder(root1->right);
    cout<<root1->data<<"\t";
}

void display(TreeNode* root1){
    int ch;
    cout<<"choose traversal :> \n1.preorder\n2.inorder\n3.postorder"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
            preorder(root1);
            break;
        case 2:
            inorder(root1);
            break;
        case 3:
            postorder(root1);
            break;
    }
}

void leafNodes(TreeNode* root1){
    if(root1==nullptr){
        return;
    }
    if(root1->left==nullptr && root1->right==nullptr){
        cout<<root1->data<<" "<<endl;
    }
    leafNodes(root1->left);
    leafNodes(root1->right);
}
int height(TreeNode* root1){
    if(root1==nullptr){
        return 0;
    }
    int leftHeight = height(root1->left);
    int rightHeight = height(root1->right);
    return max(leftHeight,rightHeight)+1;
}

bool findAncestor(TreeNode* root1,int x){
    if(root1==nullptr){
        return false;
    }
    if(root1->data == x){
        cout<<root1->data<<" -> "<<endl;
        return true;
    }
    if(findAncestor(root1->left,x) || findAncestor(root1->right,x)){
        cout<<root1->data<<" -> ";
        return true;
    }
    return false;
}

int countNodes(TreeNode* root1){
    if(root1==nullptr){
        return 0;
    }

    return 1+countNodes(root1->left)+countNodes(root1->right);
}
int main(){
    root = nullptr;
    int c,ch;
    cout<<"choose operations on Binary Tree :> "<<endl;
    do{
        cout<<"1.insert\n2.no of nodes\n3.leaf nodes\4.height of tree\n5.ancestor of node\n6.display"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                create(root);
                break;
            case 2:
                cout<<"No of nodes :> "<<countNodes(root)<<endl;
                break;
            case 3:
                leafNodes(root);
                break;
            case 4:
                cout<<"Height of tree :> "<<height(root)<<endl;
                break;
            case 5:
                int x;
                cout<<"ENter data whose ancestor want to find :> "<<endl;
                cin>>x;
                findAncestor(root,x);
                break;
            case 6:
                display(root);
                break;
        }
    }while(ch<=6);
    cout<<"Program terminated..."<<endl;
    return 0;
}