#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->val = data;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* root = nullptr;
void dfs(TreeNode* root, vector<vector<int>>& ans, vector<int> path, int targetSum,int currentSum){
    if(root==nullptr) return;
    path.push_back(root->val);
    currentSum += root->val;

    if(root->left == nullptr && root->right==nullptr){
        if(currentSum == targetSum){
            ans.push_back(path);
        }
    }else{
        dfs(root->left,ans,path,targetSum,currentSum);
        dfs(root->right,ans,path,targetSum,currentSum);
    }
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root,int targetSum){
    vector<int> path;
    vector<vector<int>> ans;
    dfs(root,ans,path,targetSum,0);
    return ans;
}


int main(){
    TreeNode* root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    pathSum(root,7);
    //display the vector 
    //...

    return 0;
}