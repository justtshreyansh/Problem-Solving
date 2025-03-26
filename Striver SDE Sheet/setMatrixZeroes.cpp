#include<bits/stdc++.h>
using namespace std;
//marking the row 
void markRow(int i,vector<vector<int>> &matrix){
    for(int j=0;j<matrix[i].size();j++){
        matrix[i][j] = -1;
    }
}
void markCol(int j,vector<vector<int>> &matrix){
    for(int i=0;i<matrix.size();i++){
        matrix[i][j] = -1;
    }
}
void bruteForce(vector<vector<int>> &matrix){
    //brute force solution 

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==0){
                markRow(i,matrix);
                markCol(j,matrix);
            }
        }
    }

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==-1){
                matrix[i][j] = 0;
            }
        }
    }




}

void betterSolution(vector<vector<int>> &matrix){
    //extra space used here
    vector<int> col(matrix[0].size(),0);
    vector<int> row(matrix.size(),0);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==0){
                col[j]=1;
                row[i]= 1;

            }
        }
    }
    
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(col[j] || row[i]){
                matrix[i][j] = 0;
            }
        }
    }
}

void optimalSolution(vector<vector<int>> &matrix){
    int col0 = matrix[0][0];
    for(int i=1;i<matrix.size();i++){
        for(int j=1;j<matrix[i].size();j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                if(j!=0){
                    matrix[0][j] = 0;
                }
                else col0 = 0;
            
            }

            
        }
    }

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[0][j]==0 || matrix[i][0]==0){
                matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0]==0){
        for(int j=0;j<matrix[0].size();j++){
            matrix[0][j] = 0;
        }
    }
    if(col0==0){
        for(int i=0;i<matrix.size();i++){
            matrix[i][0] =0;
        }
    }
}
int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    optimalSolution(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
