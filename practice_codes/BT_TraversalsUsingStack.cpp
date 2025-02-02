//Implementing all types of traversals without using recursion -- used stack instead of recursive calling functions
#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
    public:
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
        cout<<node->data<<" ";
        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left);
    }
}
void inorder(TreeNode *root1){       //LVR
    stack<TreeNode*> s;
    TreeNode *currentNode = root1;
    while(currentNode!=nullptr || !s.empty()){
        while(currentNode != nullptr){
            s.push(currentNode);
            currentNode = currentNode->left;
        }
        currentNode = s.top();
        s.pop();
        cout<<currentNode->data<<" "<<endl;
        currentNode = currentNode->right;
    }
}
void postorder(TreeNode *root1){     //LRV
        stack<TreeNode*> s1,s2;
        s1.push(root1);
        while(!s1.empty()){
            TreeNode *node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }
    while(!s2.empty()){
        cout << s2.top()->data << " ";
        s2.pop();
    }
}
void insert(TreeNode *root1,TreeNode *newNode){
    if(root1==nullptr){
        root1 = newNode;
    }else{
        char ch;
        cout<<"select direction :(l/r) "<<endl;
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
void display(TreeNode *root1){
    if(root1==nullptr){
        cout<<"Tree is empty..!!!"<<endl;
        return;
    }else{
        int ch;
        cout<<"select traversal :> "<<endl;
        cout<<"1.preorder\n2.inorder\n3.postorder"<<endl;
        cin>>ch;
        if(ch==1) preorder(root);
        else if(ch==2) inorder(root);
        else if(ch==3) postorder(root);
    }
}
void create(){
    int x;
    cout<<"Enter value :> "<<endl;
    cin>>x;
    TreeNode *newNode = new TreeNode(x);
    if(root==nullptr){
        root = newNode;
    }else{
        insert(root,newNode);
    }
}
int main(){
    int c,ch;
    root = nullptr;
    do{
        cout<<"Select choice :"<<endl;
        cout<<"1.insert"<<endl;
        cout<<"2.display"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                create();
                break;
            case 2:
                display(root);
                break;
            default:
            cout<<"select valid option..!!!"<<endl;
        }
        cout<<"Do you want to continue ? (1/0)"<<endl;
        cin>>c;
    }while(c==1);
    return 0;
}