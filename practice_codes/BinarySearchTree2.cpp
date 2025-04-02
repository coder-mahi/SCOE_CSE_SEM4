#include<iostream>
#include<string>
using namespace std;
struct TreeNode{
    int id,sal;
    string ename;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int id,string ename,int sal){
        this->id = id;
        this->ename = ename;
        this->sal = sal;
        left = nullptr;
        right=nullptr;
    }
};
TreeNode* root = nullptr;

void insert(TreeNode*& root1,TreeNode* newNode){
    if(root1==nullptr){
        root1=newNode;
        return;
    }
    if(newNode->sal < root1->sal){
        insert(root1->left,newNode);
    }else{
        insert(root1->right,newNode);
    }
}

void create(TreeNode*& root1){
    int id,sal;
    string ename;
    cout<<"enter employee id,name,salary"<<endl;
    cin>>id>>ename>>sal;
    TreeNode* temp = new TreeNode(id,ename,sal);
    if(root1==nullptr){
        root1=temp;
        return;
    }else{
        insert(root1,temp);
    }
}

void search(TreeNode* root1, int id){
    if(root1==nullptr){
        return;
    }

    if(root1->id == id){
        cout<<"Employee FOund"<<endl;
        return;
    }
    search(root1->left,id);
    search(root1->right,id);
}

TreeNode* deleteNode(TreeNode*& root1,int id){
    if(root1==nullptr){
        return root;
    }

    if(id < root1->id){
        root1->left = deleteNode(root1->left,id);
    }else if(id > root1->id){
        root1->right = deleteNode(root1->right,id);
    }else{
        // match found
        if(root1->left == nullptr && root1->right==nullptr){
            delete root1;
            return nullptr;
        }else 
        if(root1->left ==nullptr){
            TreeNode* temp = root1->right;
            delete root1;
            return temp;
        }else 
        if(root1->right==nullptr){
            TreeNode* temp = root1->left;
            delete root1;
            return temp;
        }else{
            //both children
            TreeNode* temp = root1->right;
            while(temp->left){
                temp = temp->left;
            }
            root1->id =  temp->id;
            root1->ename =  temp->ename;
            root1->sal =  temp->sal;

            root1->right = deleteNode(root1->right,temp->id);

        }
    }
    return root1;
}

void preorder(TreeNode* root1){
    if(root1==nullptr) return;
    cout<<root1->id<<", "<<root1->ename<<", "<<root1->sal<<"\t";
    preorder(root1->left);
    preorder(root1->right);
}

void inorder(TreeNode* root1){
    if(root1==nullptr) return;
    inorder(root1->left);
    cout<<root1->id<<", "<<root1->ename<<", "<<root1->sal<<"\t";
    inorder(root1->right);
}

void postorder(TreeNode* root1){
    if(root1==nullptr) return;
    postorder(root1->left);
    postorder(root1->right);
    cout<<root1->id<<", "<<root1->ename<<", "<<root1->sal<<"\t";
}

void display(TreeNode* root1){
    int ch;
    cout<<"choose traversal :> \n1.preorder\n2.inorder\n3.postorder"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
            preorder(root1);
            break;
        case 2:
            inorder(root1);
            break;
        case 3:
            postorder(root1);
            break;
    }
}

int minsalary(TreeNode* root1){
    if(root1==nullptr) return -1;
    int minsal;
    if(root1->left){
        minsal = min(minsal,minsalary(root1->left));
    }
    if(root1->right){
        minsal = min(minsal,minsalary(root1->right));
    }
    return minsal;
}

int maxsalary(TreeNode* root1){
    if(root1==nullptr) return -1;
    int maxsal;
    if(root1->left){
        maxsal = max(maxsal,maxsalary(root1->left));
    }
    if(root1->right){
        maxsal = max(maxsal,maxsalary(root1->right));
    }
    return maxsal;
}

void avgSalary(TreeNode* root1, int& count, int& total){
    if(root1==nullptr) return;
    avgSalary(root1->left,count,total);
    count++;
    total += root1->sal;
    avgSalary(root1->right,count,total);
}

int countEmpoyees(TreeNode* root1){
    if(root1==nullptr){
        return 0;
    }
    return 1+countEmpoyees(root1->left)+countEmpoyees(root1->right);
}

void update(TreeNode*& root1,int id, TreeNode* newNode){
    if(root==nullptr) return;
    if(id == root1->id){
        root1 = deleteNode(root1,id);
        if(newNode){
            insert(root1,newNode);
        }
    }else if(id < root1->id){
        update(root1->left,id,newNode);
    }else if(id> root->id){
        update(root1->right,id,newNode);
    }
}
int main(){
    root = nullptr;
    int c,ch,x;
    int count=0,total=0;

    cout<<"choose operations on Binary Search Tree :> "<<endl;
    do{
        cout<<"1.insert\n2.search\n3.delete employee\4.display\n5.min salary\n6.max salary\n7.avg salary\n8.no of employees\n9.update"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                create(root);
                break;
            case 2:
                cout<<"enter id of emp :> "<<endl;
                cin>>x;
                search(root,x);
                break;
            case 3:
                cout<<"enter id of emp to delete :>"<<endl;
                cin>>x;
                root = deleteNode(root,x);
                break;
            case 4:
                display(root);
                break;
            case 5:
                cout<<"Min salary :> "<<minsalary(root);
                break;
            case 6:
                cout<<"Max salary :> "<<maxsalary(root);
                break;
            case 7:
                total = 0;
                count = 0;
                avgSalary(root,count,total);
                if(count>0){
                    cout<<"avg salarry :>"<<(total/count)<<endl;
                }else{
                    cout<<"No employees found..!!!"<<endl;
                }
                break;
            case 8:
                cout<<"Total employees :> "<<countEmpoyees(root);
                break;
            case 9:
                int id,sal;
                string ename;
                cout<<"enter id of emp which you wnat to update ?"<<endl;
                cin>>x;
                cout<<"Enter new id,name,salary :> "<<endl;
                cin>>id>>ename>>sal;
                TreeNode* temp = new TreeNode(id,ename,sal);
                update(root,x,temp);
                break;
        }
    }while(ch<10);
    return 0;
}
