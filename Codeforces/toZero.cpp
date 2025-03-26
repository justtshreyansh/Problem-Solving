#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int ans = 0;
        //n is even 
        if(n%2==0){
            k-=1;
            
            if(n%k==0) ans = n/k;
            else ans = n/k+1;
        }
        //n is odd
        else{
            n-=k;
            k--;
            if(n%k==0) ans = n/k+1;
            else ans = n/k+2;
        }
        cout<<ans<<endl;
    }
    return 0;
}