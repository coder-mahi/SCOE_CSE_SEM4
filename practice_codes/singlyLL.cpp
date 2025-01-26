#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
}*headd, *temp, *indexx;
void insertAtFirst(Node *head, int val){
    temp = new Node(val);
    if (head == nullptr){
        head = temp;
    }
    else{
        head->next = temp;
    }
}
void insertAtLast(Node *head, int val){
    temp = new Node(val);
    if (head == nullptr){
        head = temp;
    }
    else{
        indexx = head;
        while (indexx->next->next != nullptr){
            indexx = indexx->next;
        }
        indexx->next->next = temp;
        temp->next = nullptr;
    }
}
void insertAtSpecificLoc(Node *head, int i){
    int check = 0;
    if (head == nullptr){
        cout << "Can't insert at index " << i << endl;
    }
    else{
        int count = 0;
        indexx = head;
        while (indexx->next != nullptr){
            if (count == i){
                int val;
                cout << "Enter value :" << endl;
                cin >> val;
                Node *newNode = new Node(val);
                temp = indexx->next;
                indexx->next = newNode;
                newNode->next = temp;
                check = 1;
                break;
            }
            count++;
            indexx = indexx->next;
        }
    }
    if (check == 1){
        cout << "Inserted succesfully...!!" << endl;
    }
    else{
        cout << "Something went wrong...!!" << endl;
    }
}
void deleteAtFirst(Node *head){
}
void deleteAtLast(Node *head){
}
void deleteAtSpecificLoc(Node *head){
}
void displayLL(Node *head){
    if (head == nullptr){
        cout << "Linked list is empty" << endl;
    }else{
        indexx = head;
        while (indexx->next != nullptr){
            cout << " " << indexx->data << "-> ";
            indexx = indexx->next;
        }
    }
}
int main(){
    int val, ch, c, i;
    headd = nullptr;
    do{
        cout << "Operations Menu :>" << endl;
        cout << "1. Insert at first" << endl;
        cout << "2. Insert at last" << endl;
        cout << "3. Insert at specific location" << endl;
        cout << "4. Delete at first" << endl;
        cout << "5. Delete at last" << endl;
        cout << "6. Delete at specific location" << endl;
        cout << "7. Display Linked List" << endl;
        cin >> ch;
        switch (ch){
        case 1:
            cout << "Enter value :" << endl;
            cin >> val;
            insertAtFirst(headd, val);
            break;
        case 2:
            cout << "Enter value :" << endl;
            cin >> val;
            insertAtLast(headd, val);
            break;
        case 3:
            cout << "Enter index :" << endl;
            cin >> i;
            insertAtSpecificLoc(headd, i);
            break;
        case 4:
            deleteAtFirst(headd);
            break;
        case 5:
            deleteAtLast(headd);
            break;
        case 6:
            deleteAtSpecificLoc(headd);
            break;
        case 7:
            displayLL(headd);
            break;
        default:
            cout << "Invalid Option Selection!!!!!" << endl;
        }
        cout << "DO you want to continue ? is yes(1)" << endl;
        cin >> c;
    } while (c == 1);
    return 0;
}