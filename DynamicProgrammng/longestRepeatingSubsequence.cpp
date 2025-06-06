#include<bits/stdc++.h>
using namespace std;
int topDownDp(string a,int n,vector<vector<int>> &dp){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(a[i-1]==a[j-1] && i!=j){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][n];
}
int main(){
    string a = "aabbeeddfe";
    int n =a.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    cout<<topDownDp(a,n,dp)<<endl;
    return 0;
}