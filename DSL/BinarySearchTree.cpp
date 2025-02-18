//BST using recursive approach
#include <iostream>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};
class BST {
public:
    TreeNode* root;
    BST() {
        root = nullptr;
    }
    TreeNode* insert(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }
        return root;
    }
    bool search(TreeNode* root, int key) {
        if (root == nullptr) {
            return false;
        }
        if (root->data == key) {
            return true;
        }
        if (key < root->data) {
            return search(root->left, key);
        }
        return search(root->right, key);
    }
    void inorder(TreeNode* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};
int main() {
    BST tree;
    int choice, value;
    do {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Insert\n2. Search\n3. Inorder Traversal\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Enter value to insert: ";
                cin >> value;
                tree.root = tree.insert(tree.root, value);
                cout << value << " inserted successfully!\n";
                break;
            case 2: 
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(tree.root, value)) {
                    cout << value << " found in BST.\n";
                } else {
                    cout << value << " not found in BST.\n";
                }
                break;
            case 3:
                cout << "BST (Inorder Traversal): ";
                tree.inorder(tree.root);
                cout << endl;
                break;
            case 4: 
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    return 0;
}