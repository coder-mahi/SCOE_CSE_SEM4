//0124UCSM2008
#include<iostream>
using namespace std;
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
TreeNode* root = nullptr;
void insert(TreeNode* &root1, TreeNode* newNode) {
    if (root1 == nullptr) {
        root1 = newNode;
    } else {
        char ch;
        cout << "Select left or right (l/r) : " << endl;
        cin >> ch;
        if (ch == 'l' || ch == 'L') {
            if (root1->left == nullptr) {
                root1->left = newNode;
            } else {
                insert(root1->left, newNode);
            }
        } else if (ch == 'r' || ch == 'R') {
            if (root1->right == nullptr) {
                root1->right = newNode;
            } else {
                insert(root1->right, newNode);
            }
        }
    }
}

void preorder(TreeNode* root1) {
    if (root1 == nullptr) return;
    cout << root1->data << " -> ";
    preorder(root1->left);
    preorder(root1->right);
}

void inorder(TreeNode* root1) {
    if (root1 == nullptr) return;
    inorder(root1->left);
    cout << root1->data << " -> ";
    inorder(root1->right);
}

void postorder(TreeNode* root1) {
    if (root1 == nullptr) return;
    postorder(root1->left);
    postorder(root1->right);
    cout << root1->data << " -> ";
}

void display(TreeNode* root1) {
    if (root1 == nullptr) {
        cout << "Tree is empty...!!!" << endl;
        return;
    }
    int ch;
    cout << "Choose traversal : " << endl;
    cout << "1. Preorder" << endl;
    cout << "2. Inorder" << endl;
    cout << "3. Postorder" << endl;
    cin >> ch;
    switch (ch) {
        case 1: 
        		preorder(root1); 
        		break;
        case 2: 
        		inorder(root1); 
        		break;
        case 3: 
        		postorder(root1); 
        		break;
        default: 
        		cout << "Invalid choice..!!!" << endl;
    }
}

void create() {
    int val;
    cout << "Enter value: ";
    cin >> val;
    TreeNode* newNode = new TreeNode(val);
    if (root == nullptr) {
        root = newNode;
    } else {
        insert(root, newNode);
    }
}

int countNodes(TreeNode* root1) {
    if (root1 == nullptr) return 0;
    return 1 + countNodes(root1->left)+countNodes(root1->right);
}

void leafNodes(TreeNode* root1) {
    if (root1 == nullptr) {
    	return;    
    }
    if (root1->left == nullptr && root1->right == nullptr) {
        cout << root1->data << endl;
    }
    leafNodes(root1->left);
    leafNodes(root1->right);
}

bool findAncestor(TreeNode* root1, int val) {
    if (root1 == nullptr) {
    		return false;
    }
    if (root1->data == val) {
        cout << root1->data << " -> ";
        return true;
    }
    if(findAncestor(root1->left,val) || findAncestor(root1->right,val)){
        cout << root1->data << " -> ";
        return true;
    }
    return false;
}

int countHeightOfTree(TreeNode* root1){
    if(root1==nullptr){
   		 return 0;
    }
    int leftHeight =countHeightOfTree(root1->left);
    int rightHeight =countHeightOfTree(root1->right);
    return max(leftHeight,rightHeight)+1;
}

int main() {
    int ch, val, c;
    do {
        cout<<"Select operation on Binary Tree : "<<endl;
        cout<<"1. Insert\n2. Number of nodes\n3. Leaf nodes\n4. Ancestor of node\n5.Height of tree\n6. Display" << endl;
        cin >> ch;
        switch (ch) {
            case 1: 
            	create(); 
            	break;
            case 2: 
            	cout << "Total nodes:"<<countNodes(root)<<endl; 
            	break;
            case 3: 
            	cout<<"Leaf nodes: "<<endl; 
            	leafNodes(root); 
            	break;
            case 4:
                cout<<"Enter node value to find ancestor: ";
                cin>>val;
                if (findAncestor(root,val)==false) {
                    cout << "Ancestor not found!!!!!" << endl;
                }
                break;
            case 5: 
            	cout<<"Height of tree: "<<countHeightOfTree(root)<<endl; 
            	break;
            case 6: 
            		display(root); 
            		break;
            default: 
            		cout<<"Invalid option!" << endl;
        }
        cout << "Do you want to continue? (1/0) : ";
        cin >> c;
    } while (c==1);
    return 0;
}

