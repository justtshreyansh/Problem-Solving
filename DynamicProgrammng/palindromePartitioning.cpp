#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){

            return false;
        }
        i++;
        j--;
    }
    return true;
}
int memoization(string s,int i,int j,vector<vector<int>> &dp){
    if(i>=j){
        return 0;
    }
    if(isPalindrome(s,i,j)){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = 1 + memoization(s,i,k,dp) + memoization(s,k+1,j,dp);
        mini =  min(mini,temp);
    }
    return mini;


}
int main(){
    string s = "aaaab";
    int n = s.size();
    vector<vector<int>> dp(n,vector<int> (n,-1));
    cout<<memoization(s,0,n-1,dp)<<endl;

    return 0;
}