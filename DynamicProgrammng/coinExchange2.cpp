#include<bits/stdc++.h>
using namespace std;
int tabulation(vector<int> &coins,int sum,vector<vector<int>> &dp,int n){
    //initialising the dp - > first column as 1 
    for(int i=0;i<=sum;i++){
        dp[0][i] = INT_MAX-1;//because at the line 17 we are adding 1 so this will become intmax-1
    }
    //initialising the second row
    for(int i=1;i<=sum;i++){
        if(i%coins[0]==0) dp[1][i] = i/coins[0];
        else dp[1][i] = INT_MAX-1;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1]<=j){
                dp[i][j] = min(dp[i][j-coins[i-1]]+1 , dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    vector<int> coins = {1,2,3};
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