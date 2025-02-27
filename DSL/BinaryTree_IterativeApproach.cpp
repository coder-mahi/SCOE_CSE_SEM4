//without using recursion
#include<iostream>
#include<stack>
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
void preorder(TreeNode *root1){     //VLR
    stack<TreeNode*> s;
    s.push(root1);
    while(!s.empty()){       
        TreeNode *node = s.top();
        s.pop();
        cout<<node->data<<" "<<endl;
        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left);
    }
}
void inorder(TreeNode *root1){      //LVR
   stack<TreeNode*> s;
    TreeNode* current = root1;
    while(current != NULL || !s.empty()) {
        while(current != NULL) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout<<current->data << " ";
        current=current->right;
    }
}
void postorder(TreeNode *root1){     //LRV
    stack<TreeNode*> s1, s2;
    s1.push(root1);
    while(!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);
        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}
void insert(TreeNode *root1,TreeNode *newNode){
    if(root1==nullptr){
        root1=newNode;
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
            break;
            default:
            cout<<"select valid option..."<<endl;
        }
        cout<<"Do you want to continue ? if yes hit 1"<<endl;
        cin>>c;
    }while(c==1);
    return 0;
}