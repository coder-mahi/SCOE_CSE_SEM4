#include <iostream>
using namespace std;

// Node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// BST Class
class BST {
public:
    Node* root;

    // Constructor
    BST() {
        root = nullptr;
    }

    // Insert function
    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }
        return root;
    }

    // Search function
    bool search(Node* root, int key) {
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

    // Inorder Traversal (Left -> Root -> Right)
    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

// Main Function
int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Insert\n2. Search\n3. Inorder Traversal\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Insert
                cout << "Enter value to insert: ";
                cin >> value;
                tree.root = tree.insert(tree.root, value);
                cout << value << " inserted successfully!\n";
                break;

            case 2: // Search
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(tree.root, value)) {
                    cout << value << " found in BST.\n";
                } else {
                    cout << value << " not found in BST.\n";
                }
                break;

            case 3: // Inorder Traversal
                cout << "BST (Inorder Traversal): ";
                tree.inorder(tree.root);
                cout << endl;
                break;

            case 4: // Exit
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}