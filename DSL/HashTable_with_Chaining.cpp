#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Chain {
private:
    vector<list<int>> table;
    int Size;

    int hash(int k) {
        return k % Size;
    }

public:
    Chain(int size) {
        this->Size = size;
        table.resize(Size);
    }

    void Insert(int k) {
        int index = hash(k);
        table[index].push_back(k);
        cout<<k<<" is added successfully"<<endl;
    }

    void Display() {
        for (int i = 0; i < Size; i++) {
            cout << "Index " << i << ": ";
            for (int key : table[i]) {
                cout << key << " -> ";
            }
            cout << "null" << endl;
        }
    }

    bool Search_K(int searchkey) {
        int index = hash(searchkey);
        for (int key : table[index]) {
            if (key == searchkey) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int size;
    cout << "Enter the size of the table: ";
    cin >> size;

    Chain cn(size);

    while (true) {
        cout << "*** Menu ***\n1.Insert\n2.Display\n3.Search\n4.Exit" << endl;
        cout << "Enter your choice: ";
        int ch;
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "Enter the number of keys to insert: ";
                int numKeys;
                cin >> numKeys;
                cout << "Enter the keys: ";
                for (int i = 0; i < numKeys; i++) {
                    int k;
                    cin >> k;
                    cn.Insert(k);
                }
                break;
            }
            case 2:
                cout << "Hash table" << endl;
                cn.Display();
                break;
            case 3: {
                cout << "Enter the key to search: ";
                int searchkey;
                cin >> searchkey;
                if (cn.Search_K(searchkey)) {
                    cout << "Key found!" << endl;
                } else {
                    cout << "Key not found!" << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice..Try Again" << endl;
        }
    }

    return 0;
}