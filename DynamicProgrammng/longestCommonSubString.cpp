#include<bits/stdc++.h>
using namespace std;
int recursive(string a,string b,int n,int m){
    if(n==0 || m==0){
        return 0;
    }

    if(a[n-1]==b[m-1]){
        return 1+recursive(a,b,n-1,m-1);
    }
    else{
        return 0;
    }
}

int memoization(string a,string b,int n,int m,vector<vector<int>> &dp){
    if(n==0 || m==0) return 0;

    if(dp[n][m] !=-1){
        return dp[n][m];
    }
    if(a[n-1]==b[m-1]){
        dp[n][m] = 1+ memoization(a,b,n-1,m-1,dp);
    }
    else{
        dp[n][m] = 0;
    }
    return dp[n][m];
}

int topDownDp(string a,string b,int n,int m,vector<vector<int>> &dp){


    for(int i=0;i<=n;i++){
        
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dp[i][j] =0;
            else if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    int maxi = 0;
    for(int i=0;i<=n;i++){
       
        for(int j=0;j<=m;j++){
            maxi = max(maxi,dp[i][j]);
        }
    }
    return maxi;
}
int main(){
    string a = "abcdgh";
    string b = "abedfgh";
    int n = a.size();
    int m  = b.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    cout<<topDownDp(a,b,n,m,dp)<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}