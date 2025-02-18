//using recursive approach...
#include<iostream>
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
TreeNode* insert(TreeNode* root,int val){
    if(root==nullptr){
        return new TreeNode(val);
    }
    if(val<root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;
}

void inOrderTraversal(TreeNode *root){         //LVR
    if(root==nullptr){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
} 
void preOrderTraversal(TreeNode *root){        //VLR
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(TreeNode *root){       //LRV
    if(root==nullptr){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
int main() {
    TreeNode* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);

    cout << "Inorder Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preOrderTraversal(root);
    cout << endl;
    
    cout << "Postorder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}