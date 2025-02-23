/* operations on BST-->
create 
search 
update 
display 
minimum salary 
maximum salary 
find avg sal
total no. of employees
delete employee */
#include<iostream>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
}*root;
int n;
int avg;
void insert(TreeNode*& root1, TreeNode* newNode){
    if(root1 == nullptr){
        root1 = newNode;
        return;
    }
    if(newNode->data < root1->data){
        insert(root1->left,newNode);
    }else{
        insert(root1->right,newNode);
    }
}

void create(TreeNode*& root1){
    int x;
    if(root1==nullptr){
        cout<<"Enter no. of employees you want to insert:"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            TreeNode* newNode = new TreeNode(x);
            insert(root1,newNode);
            cout<<" ->inserted successfully";
        }
    }else{
        cout<<"Employees already inserted by you.."<<endl;
    }
}

void update(TreeNode* root1,int x,int y){
    if(root1==nullptr) {
        cout<<"Node is NULL"<<endl;
        return;
    }else{
        if(x == root1->data){
            root1->data = y;
            return;
        }
        if(x < root1->data){
            update(root1->left,x,y);
        }else{
            update(root1->right,x,y);
        }
    }
}


void search(TreeNode* root1, int x){
    if(root1 == nullptr){
        cout<<"Not found..."<<endl;
        return;
    }
    if(x==root1->data){
        cout<<"Data found.."<<endl;
        return;
    }
    if(x<root1->data){
        search(root1->left,x);
    }else{
        search(root1->right,x);
    }
}


void display(TreeNode* root1){
    if(root1==nullptr){
        return;
    }else{
        display(root1->left);
        cout<<root1->data<<" ";  
        display(root1->right);
    }
}


TreeNode* minSalary(TreeNode* root1){
    if(root1 == nullptr) return nullptr;
    while(root1->left != nullptr){
        root1 = root1->left;  
    }
    return root1;
}

TreeNode* maxSalary(TreeNode* root1){
    if(root1 == nullptr) return nullptr;
    while(root1->right != nullptr){
        root1 = root1->right;
    }
    return root1;
}

void findAvgSalary(TreeNode* root1, int& count, int& total){
    if(root1==nullptr) return;
    findAvgSalary(root1->left, count, total);
    total += root1->data;
    count++;
    findAvgSalary(root1->right, count, total);
}

int totalEmployees(TreeNode* root1){
    if(root1==nullptr){
        return -1;
    }
    return 1+max(totalEmployees(root1->left),totalEmployees(root1->right));
}

TreeNode* deleteEmployees(TreeNode* root1, int x) {
    if (root1 == nullptr) return root1;

    if (x<root1->data) {
        root1->left = deleteEmployees(root1->left,x);
    }else 
        if(x>root1->data) {
        root1->right = deleteEmployees(root1->right,x);
    }else{
        if(root1->left==nullptr && root1->right==nullptr) {    //leaf nodee
            delete root1;
            return nullptr;
        }else if(root1->left==nullptr) {     //having only left child
            TreeNode* temp = root1->right;
            delete root1;
            return temp;
        } else if (root1->right == nullptr) { //right
            TreeNode* temp = root1->left;
            delete root1;
            return temp;
        } else {
            TreeNode* temp2 = root1->right; //both
            while(temp2->left) {
                temp2=temp2->left;
            }
            root1->data =temp2->data;
            root1->right = deleteEmployees(root1->right,temp2->data);
        }
    }
    return root1;
}

void findJuniorEmployees(TreeNode* root1,int x) {
    if (root1==nullptr) return;
    if (x > root1->data) {  
        cout<<root1->data<<" "; 
         findJuniorEmployees(root1->right,x);
    }
    findJuniorEmployees(root1->left,x);
}

void findseniorEmployees(TreeNode* root1, int x) {
    if (root1 == nullptr) return;
    if (x < root1->data) {  
        display(root1); 
        findseniorEmployees(root1->left, x);
    } else {
        findseniorEmployees(root1->right, x);
    }
}


int main(){
    int ch,c;
    int count=0, total=0;
    int x,y,sal;
    root = nullptr;
    TreeNode* min =nullptr;
    TreeNode* max =nullptr;

    do{
        cout<<"Select operation on BST -> "<<endl;
        cout<<"1.create\n2.search\n3.update\n4.display\n5.minimum salary\n6.maximum salary\n7.find avg salary\n8.total no. of employee\n9.delete employee\n10.find junniors\n11.find seniors"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                create(root);
                break;
            case 2:
                cout<<"Enter search value :"<<endl;
                cin>>x;
                search(root,x);
                break;
            case 3:
                cout<<"Enter value to update : "<<endl;
                cin>>x;
                cout<<"Enter new Value : "<<endl;
                cin>>y;
                update(root,x,y);
                break;
            case 4:
                display(root);
                break;
            case 5:
                min = minSalary(root);
                if(min!=nullptr){
                    cout<<"Min sal :> "<<min->data<<endl;
                }else{
                    cout<<"tree is empty!!"<<endl;
                }
                break;
            case 6:                
                max=maxSalary(root);
                if(max!=nullptr){
                    cout<<"max sal :>"<<max->data<<endl;
                }else{
                    cout<<"tree is empty!!!"<<endl;
                }
                break;
                
            case 7:
                count = 0;
                total = 0;
                findAvgSalary(root, count, total);
                if(count>0){
                    cout<<"avg salarry :>"<<(total/count)<<endl;
                }else{
                    cout<<"No employees found..!!!"<<endl;
            }
                break;
            case 8:
                cout<<"no of employees :>"<<totalEmployees(root)<<endl;
                break;
            case 9:
                cout<<"Enter employee salary to delete :> "<<endl;
                cin>>x;
                root = deleteEmployees(root,x);
                break;
            case 10:
                cout<<"Enter salary whose juniors you want to find ?"<<endl;
                cin>>sal;
                findJuniorEmployees(root,sal);
                break;
            case 11:
                cout<<"Enter salary whose seniors you want to find ? "<<endl;
                cin>>sal;
                findseniorEmployees(root,sal);
                break;
            default:
                cout<<"invalid choice selected..."<<endl;
        }
        cout<<"Do you want to continue??"<<endl;
        cin>>c;
    }while(c==1);
    return 0;
}

