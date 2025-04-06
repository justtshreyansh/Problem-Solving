#include<bits/stdc++.h>
using namespace std;
int tabulation(vector<int> &coins,int sum,vector<vector<int>> &dp,int n){
    //initialising the dp - > first column as 1 
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1]<=j){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    vector<int> coins = {1,5,2};
    int sum = 5;
    int n = coins.size();
    vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
    cout<<tabulation(coins,sum,dp,n)<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}