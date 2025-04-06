#include<bits/stdc++.h>
using namespace std;
int topDownDp(string a,string b,int n,int m,vector<vector<int>> &dp){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int maxi = dp[n][m];
    return n+m-2*maxi;
}
int main(){
    string a = "shreyansh";
    string b = "sneha";
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    cout<<topDownDp(a,b,n,m,dp)<<endl;
    return 0;
}