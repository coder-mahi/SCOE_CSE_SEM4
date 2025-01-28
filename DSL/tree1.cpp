//simple structure of binary tree
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
int main(){
    TreeNode *root = new TreeNode(10);
    TreeNode *child1 = new TreeNode(20);
    TreeNode *child2 = new TreeNode(30);
    root->left = child1;
    root->right = child2;
    return 0;
}