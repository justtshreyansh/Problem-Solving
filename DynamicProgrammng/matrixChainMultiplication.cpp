#include<bits/stdc++.h>
using namespace std;
int recursive(vector<int> &arr,int i,int j){
    if(i>=j) return 0;
    int mini = INT_MAX;
    for(int k=i;k<j;k++){
        int ans = recursive(arr,i,k) + recursive(arr,k+1,j) + arr[i-1]  * arr[k] * arr[j];
        mini = min(mini,ans);
    }
    
    return mini;
}

int memoization(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = INT_MAX;
    for(int k=i;k<j;k++){
        int ans = memoization(arr,i,k,dp) + memoization(arr,k+1,j,dp) + arr[i-1]  * arr[k] * arr[j];
        mini = min(mini,ans);
    }
    dp[i][j] = mini;
    return mini;
    
}
int main(){
    vector<int> arr= {10,20,30,40};
   
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (n,-1));

    cout<<memoization(arr,1,n-1,dp)<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}