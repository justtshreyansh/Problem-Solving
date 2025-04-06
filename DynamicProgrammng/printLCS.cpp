#include<bits/stdc++.h>
using namespace std;
void topDownDp(string a,string b,int n,int m,vector<vector<int>> &dp){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(a[i-1]==b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
}
void printLCS(vector<vector<int>> &dp,string a,string b,int n,int m){
    int i = n;
    int j = m;
    string ans = "";
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans+=a[i-1];
            i--;
            j--;
        }
        else {
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
int main(){
    string a = "abcdfg";
    string b = "abedgh";
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    topDownDp(a,b,n,m,dp);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    printLCS(dp,a,b,n,m);
    return 0;
}