#include<bits/stdc++.h>
using namespace std;
int tabulation(vector<int> &length,vector<int> &price,int len,int n,vector<vector<int>> &dp){
    if(n==0 || len==0){
        dp[n][len] = 0;
    }
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=len;j++){
            if(length[i-1]<=j){
                dp[i][j]= max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][len];
}
int main(){
    vector<int> length = {1,2,3,4};
    vector<int> price = {2,6,8,8};
    
    int n = length.size();
    int len = 8;
    vector<vector<int>> dp(n+1,vector<int> (len+1,0));
    cout<<tabulation(length,price,len,n,dp)<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=len;j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}