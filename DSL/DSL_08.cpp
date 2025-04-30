#include <iostream>
using namespace std;
#define MAX 100

void optimalBST(float p[], float q[], int keys[], int n) {
    float c[MAX][MAX]={0}; 
    float w[MAX][MAX] ={0}; 
    float r[MAX][MAX] ={0}; 

    for (int i=0;i<=n;i++){
        for (int j = i; j <= n; j++) {
            if (i == j) {
                w[i][j] = q[i];
            } else {
                w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
            }
        }
    }

    for(int i = 0; i<=n; i++) {
        c[i][i] = 0; 
    }

    for(int l = 1;l<=n;l++)
    {
        for(int i=0;i<=n-l;i++) 
        {
            int j = i+l;
            c[i][j] =9999;
            for(int k=i+1; k<=j; k++) 
            { 
                int cost= c[i][k-1] + c[k][j]+w[i][j];
                if(cost<c[i][j]) 
                {
                    c[i][j] =cost;
                    r[i][j]= k;
                }
            }
        }
    }

    cout<<"Weight Matrix (w) :"<<endl;
    for(int i=0; i<=n;i++) {
        for(int j=0; j<=n; j++) 
        {
            cout<<w[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"\nCost Matrix (c):"<<endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << c[i][j] << "\t";
        }
        cout<<endl;
    }

    cout << "\nRoot Matrix (r):" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << r[i][j] << "\t";
        }
        cout<<endl;
    }

    cout<<"\nOptimal Cost of the bst :>"<<c[0][n]<<endl;

    
}

int main() {
    int n = 4; 
    int keys[] = {10, 20, 30,40}; 
    float p[] = {3,3,1,1}; 
    float q[] = {2,3,1,1,1}; 
    
    optimalBST(p, q, keys, n);
    return 0;
}