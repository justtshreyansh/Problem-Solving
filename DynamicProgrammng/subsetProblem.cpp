#include<bits/stdc++.h>
using namespace std;
bool recursive(vector<int> &arr,int sum,int n){
    if(sum==0)return true;
    if(n==0) return false;

    if(arr[n-1]<=sum){
        return max(recursive(arr,sum-arr[n-1],n-1),recursive(arr,sum,n-1));
    }
    else return recursive(arr,sum,n-1);
}
bool memoization(vector<int> &arr,int sum,int n,vector<vector<bool>> &dp){
    if(sum==0) return true;
    if(n==0) return false;

    if(dp[n][sum]!=false){
        return dp[n][sum];
    }

    if(arr[n-1]<=sum){
        dp[n][sum] = max(memoization(arr,sum-arr[n-1],n-1,dp),memoization(arr,sum,n-1,dp));
        return dp[n][sum];
    }
    else{
        dp[n][sum] = memoization(arr,sum,n-1,dp);
        return dp[n][sum];
    }
}

bool topDownDp(vector<int> &arr,int sum,int n,vector<vector<bool>> &dp){
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
           
            
            if(arr[i-1]<=j){
                dp[i][j] = max(dp[i-1][j-arr[i-1]],dp[i-1][j]);
                
            }
            else{
                dp[i][j] = dp[i-1][j];
                
            }
        }
    }

    return dp[n][sum];
}
int main(){
    vector<int> arr = {1,2,7};
    int sum = 10;
    int n = arr.size();
    vector<vector<bool>> dp(n+1,vector<bool> (sum+1,false));
    cout<<topDownDp(arr,sum,n,dp)<<endl;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}