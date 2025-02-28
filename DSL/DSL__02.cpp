#include<iostream>
#include<string>
using namespace std;
struct TreeNode{
    int id;
    string name;
    int sal;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int id,string name,int sal){
        this->id = id;
        this->name = name;
        this->sal = sal;
        left = nullptr;
        right = nullptr;
    }
}*root;
void insert(TreeNode*& root,TreeNode* newNode){
    if(root==nullptr){
        root=newNode;
        return;
    }else{
        if(newNode->id < root->id){
            insert(root->left,newNode);
        }else{
            insert(root->right,newNode);
        }
    }
}
void create(TreeNode*& root){
    int id;
    string name;
    int sal;
    cout<<"Enter ID,Name,Salary of emp -> "<<endl;
    cin>>id;
    cin>>name;
    cin>>sal;
    TreeNode* temp= new TreeNode(id,name,sal);
    insert(root,temp);
}
void display(TreeNode* root){
    if(root==nullptr) return;
    display(root->left);
    cout<<"ID : "<<root->id<<", Name : "<<root->name<<", Salary : "<<root->sal<<"\n"<<endl;
    display(root->right);
}
TreeNode* deleteNode(TreeNode*& root,int id){
    if(root==nullptr) return root;
    if(id < root->id){
        root->left = deleteNode(root->left,id);
    }else if(id > root->id){
        root->right = deleteNode(root->right,id);
    }else{ //equal to ID
        if(root->left == nullptr && root->right == nullptr){//leaf
            delete root;
            return nullptr;
        }else if(root->left == nullptr){ //one child right
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){ //one child right
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }else{ //both childern present ---inorder succesor
            TreeNode* temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            root->id = temp->id;
            root->name = temp->name;
            root->sal = temp->sal;

            root->right = deleteNode(root->right,temp->id); //delete inorder succesor
        }
    }
    return root;
}


void update(TreeNode*& root, int id, TreeNode* newNode) {
    if(root==nullptr){
        return;
    }
    if(id==root->id) {
        root=deleteNode(root,id);  
        if(newNode){
            insert(root,newNode);
        }
        return;
    } 
    else if(id<root->id) {
        update(root->left,id,newNode);
    } 
    else {
        update(root->right,id,newNode);
    }
}

void search(TreeNode* root, int x){
    if(root == nullptr){
        cout<<"Employee data Not found..."<<endl;
        return;
    }
    if(x==root->id){
        cout<<"Employee Data found.."<<endl;
        return;
    }
    if(x<root->id){
        search(root->left,x);
    }else{
        search(root->right,x);
    }
}


int minSalary(TreeNode* root)
{
    if(root==nullptr){
        cout<<"Tree is emptty"<<endl;
        return -1;
    }
    int minSal;
    if(root->left) minSal = min(minSal,minSalary(root->left));
    if(root->right) minSal = min(minSal,minSalary(root->right));
    return minSal;
}

int maxSalary(TreeNode* root)
{
    if(root==nullptr){
        cout<<"Tree is emptty"<<endl;
        return -1;
    }
    int maxSal;
    if(root->left) maxSal = max(maxSal,maxSalary(root->left));
    if(root->right) maxSal = max(maxSal,maxSalary(root->right));
    return maxSal;
}

void findAvgSalary(TreeNode* root, int& count, int& total){
    if(root==nullptr){
        return;
    }
        findAvgSalary(root->left,count,total);
        total = total+root->sal;
        count++;
        findAvgSalary(root->right, count, total);
}

int totalEmployees(TreeNode* root) 
{
    if(root==nullptr){
        return 0;
    }
    return 1+totalEmployees(root->left) +totalEmployees(root->right);
}

void findJuniorEmployees(TreeNode* root,int x)
{
    if(root==nullptr) return;
    if(x>root->id){  
        display(root); 
         findJuniorEmployees(root->right,x);
    }
    findJuniorEmployees(root->left,x);
}


void findseniorEmployees(TreeNode* root, int x)
{
    if(root == nullptr) return;
    if(x<root->id) {  
        display(root); 
        findseniorEmployees(root->left,x);
    }else {
        findseniorEmployees(root->right,x);
    }
}


int main() {
    root=nullptr;
    int id,newId,sal;
    string name;
    int ch,c,x;
    TreeNode* temp;
    int count,total;
    do{
        cout<<"Select operation on BST -> "<<endl;
        cout<<"1.create\n2.search\n3.update\n4.display\n5.minimum salary\n6.maximum salary\n7.find avg salary\n8.total no. of employee\n9.delete employee\n10.find junniors\n11.find seniors"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                create(root);
                break;
            case 2:
                cout<<"Enter id of emp to search :> "<<endl;
                cin>>x;
                search(root,x);
                break;
            case 3:
                cout<<"Enter id of emp whose details want to update ..."<<endl;
                cin>>id;
                cout<<"Enter updated id, name, salary :> "<<endl;
                cin>>newId; 
                cin>>name;
                cin>>sal;
                temp = new TreeNode(newId,name,sal);
                update(root,id,temp);
                break;
            case 4:
                display(root);
                break;
            case 5:
                cout<<"\nMinimum salary :> "<<minSalary(root)<<endl;
                break;
            case 6:
                cout<<"\nMaximum salary :> "<<maxSalary(root)<<endl;
                break;
            case 7:
                count =0;
                total =0;
                findAvgSalary(root,count,total);
                if(count>0){
                    cout<<"avg salarry :>"<<(total/count)<<endl;
                }else{
                    cout<<"No employees found..!!!"<<endl;
                }
                break;
            case 8:
                cout<<"\nTOTAL EMP :> "<<totalEmployees(root);
                break;
            case 9:
                cout<<"enter ID :> "<<endl;
                cin>>id;
                deleteNode(root,id);
                break;
            case 10:
                cout<<"enter ID :> "<<endl;
                cin>>id;
                findJuniorEmployees(root,id);
                break;
            case 11:
                cout<<"enter ID :> "<<endl;
                cin>>id;
                findseniorEmployees(root,id);
                break;
        }
        cout<<"Do you want to continue ?"<<endl;
        cin>>c;
    }while(c==1);
    return 0;
}
