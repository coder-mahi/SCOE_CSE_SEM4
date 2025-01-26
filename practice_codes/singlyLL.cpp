#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
}*temp,*indexx,*head = nullptr;

void insertAtFirst(int val) {
    temp = new Node(val);
    if (head == nullptr) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void insertAtLast(int val) {
    temp = new Node(val);
    if (head == nullptr) {
        head = temp;
    } else {
        indexx = head;
        while (indexx->next != nullptr) {
            indexx = indexx->next;
        }
        indexx->next = temp;
    }
}

void insertAtSpecificLoc(int i) {
    if (head == nullptr) {
        cout << "Can't insert at indexx " << i << endl;
        return;
    }
    int count = 0;
    indexx = head;
    while (indexx != nullptr && count < i - 1) {
        indexx = indexx->next;
        count++;
    }
    if (indexx == nullptr) {
        cout << "indexx out of bounds" << endl;
        return;
    }
    int val;
    cout << "Enter value :" << endl;
    cin >> val;
    Node *newNode = new Node(val);
    newNode->next = indexx->next;
    indexx->next = newNode;
    cout << "Inserted successfully...!!" << endl;
}

void deleteAtFirst() {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    temp = head;
    head = head->next;
    delete temp;
}

void deleteAtLast() {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    indexx = head;
    while (indexx->next->next != nullptr) {
        indexx = indexx->next;
    }
    delete indexx->next;
    indexx->next = nullptr;
}

void deleteAtSpecificLoc(int i) {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    if (i == 0) {
        deleteAtFirst();
        return;
    }
    int count = 0;
    indexx = head;
    while (indexx != nullptr && count < i - 1) {
        indexx = indexx->next;
        count++;
    }
    if (indexx == nullptr || indexx->next == nullptr) {
        cout << "indexx out of bounds" << endl;
        return;
    }
    temp = indexx->next;
    indexx->next = temp->next;
    delete temp;
}

void displayLL() {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    indexx = head;
    while (indexx != nullptr) {
        cout << indexx->data << " -> ";
        indexx = indexx->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    int val, ch, c, i;
    do {
        cout << "Operations Menu :>" << endl;
        cout << "1. Insert at first" << endl;
        cout << "2. Insert at last" << endl;
        cout << "3. Insert at specific location" << endl;
        cout << "4. Delete at first" << endl;
        cout << "5. Delete at last" << endl;
        cout << "6. Delete at specific location" << endl;
        cout << "7. Display Linked List" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter value :" << endl;
            cin >> val;
            insertAtFirst(val);
            break;
        case 2:
            cout << "Enter value :" << endl;
            cin >> val;
            insertAtLast(val);
            break;
        case 3:
            cout << "Enter indexx :" << endl;
            cin >> i;
            insertAtSpecificLoc(i);
            break;
        case 4:
            deleteAtFirst();
            break;
        case 5:
            deleteAtLast();
            break;
        case 6:
            cout << "Enter indexx :" << endl;
            cin >> i;
            deleteAtSpecificLoc(i);
            break;
        case 7:
            displayLL();
            break;
        default:
            cout << "Invalid Option Selection!!!!!" << endl;
        }
        cout << "Do you want to continue? If yes, enter 1: ";
        cin >> c;
    } while (c == 1);
    return 0;
}