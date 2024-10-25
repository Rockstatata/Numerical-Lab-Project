#include<bits/stdc++.h>
 
using namespace std;

vector<vector<double>>pivot_zero(vector<vector<double>> matrix){
    int size= matrix.size(),col = matrix[0].size();
    int j=size-1;
    set<int>rows;
    for(int i = 0;i<size;i++){
        if(matrix[i][i]==0 && rows.find(i)==rows.end()){
            rows.insert(j);
            for(int k=0;k<col;k++){
                swap(matrix[i][k],matrix[j][k]);
            }
            j--;
        }
    }
    return matrix;
}

vector<vector<double>> gauss_eli(vector<vector<double>> matrix){
    int r = matrix.size();
    int c = matrix[0].size();
    int row = r-1, col = 0;
    matrix = pivot_zero(matrix);
    for(int i=0;i<c-2;i++){
        for(int j = row;j>i;j--){
            int k = j-1;
            if(matrix[j][i]==0){
                continue;
            }
            while(k>0 && matrix[k][i]==0){
                k--;
            }
            if(k==0 && matrix[k][i]==0){
                cout<<"These equations have infinite solutions"<<endl;
                return matrix;
            }
            double x = matrix[j][i], y = matrix[k][i];
            for(int l = 0;l<c;l++){
                matrix[j][l] = (matrix[j][l]) - ((matrix[k][l] * x)/(y*1.0));
                if(fabs(matrix[j][l]) == 0.0) matrix[j][l]=0.0;
            }
        }
    }
    return matrix;
}


void display(vector<vector<double>>matrix){
    int n = matrix.size();
    for(int i = 0;i<n;i++){
        for(int j =0;j<=n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void gauss_eli(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<"Number of equations: "<<endl;
    int n;
    cin>>n;
    vector<vector<double>>matrix(n,vector<double>(n+1));
    for(int i = 0;i<n;i++){
        for(int j =0;j<=n;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<double>>result = gauss_eli(matrix);
    cout<<"Gauss Elimination Output"<<endl;
    display(result);
    
}

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<"Number of equations: "<<endl;
    int n;
    cin>>n;
    vector<vector<double>>matrix(n,vector<double>(n+1));
    for(int i = 0;i<n;i++){
        for(int j =0;j<=n;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<double>>result = gauss_eli(matrix);
    cout<<"Gauss Elimination Output"<<endl;
    display(result);
}