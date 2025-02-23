/* operations on BST--
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
void create(TreeNode* root1){
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
void insert(TreeNode* root1,TreeNode* newNode){
    if(root1 == nullptr){
        root1 = newNode;
        return;
    }else{
        if(newNode->data < root1->data){
            insert(root1->left,newNode);
        }else{
            insert(root1->right,newNode);
        }
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
void search(TreeNode* root1,int x){
    if(root1 == nullptr) return;
    if(x == root1->data){
        cout<<"Data found.."<<endl;
        return;
    }
    if(x < root1->data){
        search(root1->left,x);
    }else{
        search(root1->right,x);
    }
    cout<<"Not found..."<<endl;
}
void display(TreeNode* root1){
    if(root1!=nullptr){
        display(root1->left);
        cout<<root1->data<<" ";  
        display(root1->right);
    }
}
TreeNode* minSalary(TreeNode* root1){
    TreeNode* temp;
    while(root1->left != nullptr){
        temp = root1->left;
    }
    return temp;
}
TreeNode* maxSalary(TreeNode* root1){
    TreeNode* temp;
    while(root1->right != nullptr){
        temp = root1->right;
    }
    return temp;
}
void findAvgSalary(TreeNode* root1,int count,int total){
    if(root1==nullptr) return;
    else{
        findAvgSalary(root1->left,count,total);
        total =total+root1->data;
        count++;
        findAvgSalary(root1->right,count,total);
    }
    cout<<"Avg salarry :> "<<(total/count)<<endl;
}
void totalEmployees(TreeNode* root1,int count){
    if(root1!=nullptr){
        totalEmployees(root1->left,count);
        count++;
        totalEmployees(root1->right,count);
    }
    cout<<"No of EMployees :> "<<count<<endl;
}
void deleteEmployees(TreeNode* root1,int x){
    TreeNode* temp;
    if(root1==nullptr) return;
    if(x==root1->data){
        if(root->left==nullptr && root1->right==nullptr){ //leaf node
            temp = root1;
            delete temp;
            return;
        }else if(root1->left==nullptr||root1->right==nullptr){ //one child
            if(root1->left){
                temp = root1;
                TreeNode* child = root1->left;
                root1 = child;
                delete temp;
            }else{
                temp = root1;
                TreeNode* child = root1->right;
                root1 = child;
                delete temp;
            }
        }else{ //both child
            TreeNode* temp2 = root1->right;
            while(temp2->left){
                temp2 = temp2->left;
            }
            root1->data = temp2->data;
            deleteEmployees(root1->right, temp2->data);
        }

    }else if(x < root1->data){
        deleteEmployees(root1->left,x);
    }else{
        deleteEmployees(root1->right,x);
    }
}
int main(){
    int ch,c,count=0;
    int total=0;
    root = nullptr;
    do{
        cout<<"Select operation on BST -> "<<endl;
        cout<<"1.create\n2.search\n3.update\n4.display\n5.minimum salary\n6.maximum salary\n7.find avg salary\n8.total no. of employee\n9.delete employee"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                create(root);
                break;
            case 2:
                int x;
                cout<<"Enter search value :"<<endl;
                cin>>x;
                search(root,x);
                break;
            case 3:
                int x,y;
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
                TreeNode* temp = minSalary(root);
                cout<<"Minimum Salary :> "<<temp->data<<endl;
                break;
            case 6:                
                TreeNode* temp = maxSalary(root);
                cout<<"Maximum Salary :> "<<temp->data<<endl;
                break;
            case 7:
                findAvgSalary(root,count,total);
                break;
            case 8:
                count = 0;
                totalEmployees(root,count);
                break;
            case 9:
                cout<<"Enter employee salary to delete :> "<<endl;
                cin>>x;
                deleteEmployees(root,x);
                break;
            default:
                cout<<"invalid choice selected..."<<endl;
        }
        cout<<"Do you want to continue??"<<endl;
        cin>>c;
    }while(c==1);
    return 0;
}

