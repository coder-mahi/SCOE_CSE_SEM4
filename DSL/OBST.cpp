#include <iostream>
using namespace std;
const int MAX_SIZE= 100;

void optimalBST(float p[], float q[], int keys[], int n) 
{
    float cost[MAX_SIZE][MAX_SIZE] = {0};
    float w[MAX_SIZE][MAX_SIZE] = {0};
    int root[MAX_SIZE][MAX_SIZE] = {0};

    for(int i = 0; i<= n; i++){
        w[i][i] = q[i];
        cost[i][i] = q[i];
    }

    for(int length = 1; length <= n; length++) 
    {
        for(int i = 0; i <= n - length; i++) 
        {
            int j = i + length;
            w[i][j] = w[i][j-1] + p[j-1] + q[j];
            cost[i][j] = 999999;
            for(int k = i; k < j; k++) 
            {
                float temp = cost[i][k] + cost[k+1][j] + w[i][j];
                if(temp<cost[i][j]) 
                {
                    cost[i][j] = temp;
                    root[i][j] = k;
                }
            }
        } 
    }

    cout<<"Minimum search cost: "<<cost[0][n]<<endl;
    cout<<"Root key of optimal BST:> "<<keys[root[0][n]]<<endl;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<w[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Matrix C :> "<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<cost[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Root R :> "<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<root[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main(){
    int keys[]={10, 20, 30, 40};
    float p[] ={0.1, 0.2, 0.3, 0.1};   
    float q[] ={0.05, 0.05, 0.05, 0.05, 0.05}; 
    int n = 4; 
    optimalBST(p,q,keys,n);
    return 0;
}