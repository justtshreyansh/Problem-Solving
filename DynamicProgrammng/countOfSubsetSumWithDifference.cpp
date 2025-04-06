#include<bits/stdc++.h>
using namespace std;
int recursive(vector<int> &arr,int n,int sum){
    if(sum==0) return 1;
    if(n==0) return 0;

    return recursive(arr,n-1,sum-arr[n-1]) + recursive(arr,n-1,sum);
}
int memoization(vector<int> &arr,int n,int sum,vector<vector<int>> &dp){
    if(sum==0) return 1;
    if(n==0) return 0;

    if(dp[n][sum]!=-1) return dp[n][sum];

    if(arr[n-1]<=sum){
        dp[n][sum] = memoization(arr,n-1,sum-arr[n-1],dp) + memoization(arr,n-1,sum,dp);
        return dp[n][sum];
    }
    else{
        dp[n][sum] = memoization(arr,n-1,sum,dp);
        return dp[n][sum];
    }

    
}

int topDownDp(vector<int> &arr,int n,int sum,vector<vector<int>> &dp){
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){

            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] =  dp[i-1][j];
            }
            

        }
    }
    return dp[n][sum];
}
int main(){
    vector<int> arr = {1,1,2,3};
    int n = arr.size();
    int sum = 0;
    int diff = 1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    sum = (diff + sum )/2;
    vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
    cout<<topDownDp(arr,n,sum,dp)<<endl;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}