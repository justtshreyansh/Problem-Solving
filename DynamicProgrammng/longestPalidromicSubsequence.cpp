#include<bits/stdc++.h>
using namespace std;
int longestPalidromicSubSequence(string a,string b,int n,int m,vector<vector<int>> &dp){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;

            }
            else if(a[i-1]==b[j-1]){
                dp[i][j]  = 1+ dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}
int main(){
    string a = "agbcba";
    int n = a.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    string b = a;
    reverse(a.begin(),a.end());
    cout<<longestPalidromicSubSequence(a,b,n,n,dp)<<endl;
    return 0;
}