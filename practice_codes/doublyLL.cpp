#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node *head = nullptr;
// Function to insert a node at a specific position
void insert(int val, int pos) {
    Node *newNode = new Node(val);
    if (pos == 0) {                     // Insert at the beginning
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    Node *current = head;
    int count = 0;
    while (current != nullptr && count < pos - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to delete a node at a specific position
void deleteNode(int pos) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (pos == 0) {                   // Delete the first node
        Node *temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    Node *current = head;
    int count = 0;

    while (current != nullptr && count < pos) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    current->prev->next = current->next;

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}

void display() {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main() {
    int choice, data, pos, cont;
    do {
        cout << "Choose Option :" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data and position to insert: ";
            cin >> data >> pos;
            insert(data, pos);
            break;
        case 2:
            cout << "Enter position to delete: ";
            cin >> pos;
            deleteNode(pos);
            break;
        case 3:
            cout << "List: ";
            display();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }

        cout << "Do you want to continue? (1 for Yes, 0 for No): ";
        cin >> cont;
    } while (cont == 1);

    return 0;
}
