#include<iostream>
#include<string>
using namespace std;
struct TreeNode{
    int id;
    string name;
    int sal;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int id,string name,int sal){
        this->id = id;
        this->name = name;
        this->sal = sal;
        left = nullptr;
        right = nullptr;
    }
}*root;
void insert(TreeNode*& root,TreeNode* newNode){
    if(root==nullptr){
        root=newNode;
        return;
    }else{
        if(newNode->id < root->id){
            insert(root->left,newNode);
        }else{
            insert(root->right,newNode);
        }
    }
}
void create(TreeNode*& root){
    int id;
    string name;
    int sal;
    cout<<"Enter ID,Name,Salary of emp -> "<<endl;
    cin>>id;
    cin>>name;
    cin>>sal;
    TreeNode* temp= new TreeNode(id,name,sal);
    insert(root,temp);
}
void display(TreeNode* root){
    if(root==nullptr) return;
    display(root->left);
    cout<<"ID : "<<root->id<<", Name : "<<root->name<<", Salary : "<<root->sal<<"\n"<<endl;
    display(root->right);
}
TreeNode* deleteNode(TreeNode*& root,int id){
    if(root==nullptr) return root;
    if(id < root->id){
        root->left = deleteNode(root->left,id);
    }else if(id > root->id){
        root->right = deleteNode(root->right,id);
    }else{ //equal to ID
        if(root->left == nullptr && root->right == nullptr){//leaf
            delete root;
            return nullptr;
        }else if(root->left == nullptr){ //one child right
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){ //one child right
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }else{ //both childern present ---inorder succesor
            TreeNode* temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            root->id = temp->id;
            root->name = temp->name;
            root->sal = temp->sal;

            root->right = deleteNode(root->right,temp->id); //delete inorder succesor
        }
    }
    return root;
}


void update(TreeNode*& root, int id, TreeNode* newNode) {
    if(root==nullptr){
        return;
    }
    if(id==root->id) {
        root=deleteNode(root,id);  
        if(newNode){
            insert(root,newNode);
        }
        return;
    } 
    else if(id<root->id) {
        update(root->left,id,newNode);
    } 
    else {
        update(root->right,id,newNode);
    }
}

int main() {
    root=nullptr;
    int id,newId,sal;
    string name;
    create(root);
    display(root);

    cout<<"Enter id of emp whose details want to update ..."<<endl;
    cin>>id;

    cout<<"Enter updated id, name, salary :> "<<endl;
    cin>>newId; 
    cin>>name;
    cin>>sal;

    TreeNode* temp = new TreeNode(newId,name,sal);
    update(root,id,temp);
    cout<<"After updation --- :>"<<endl;
    display(root);
    return 0;
}
