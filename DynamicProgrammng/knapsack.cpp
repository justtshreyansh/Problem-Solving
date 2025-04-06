#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> &weight,vector<int> &val,int w,int n,vector<vector<int>> &dp){
    if(w==0 || n==0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(weight[n-1]<=w){
         dp[n][w] = max(val[n-1]+knapsack(weight,val,w-weight[n-1],n-1,dp),knapsack(weight,val,w,n-1,dp));
         
         return dp[n][w];
    }
    else if(weight[n-1]>w){
         dp[n][w]  = knapsack(weight,val,w,n-1,dp);
         return dp[n][w];
    }

    
}
int main(){
    vector<int> weight = {4,5,1};
    vector<int> val = {1,2,3};
    int w = 4;
    int n = weight.size();
    vector<vector<int>> dp(n+1,vector<int> (w+1,-1));
    
    cout<<knapsack(weight,val,w,weight.size(),dp)<<endl;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}