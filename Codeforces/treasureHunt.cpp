#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    //x khatam kiya toh no otherwisey  -> yes
    while(t--){
        //1  2  5
        int x,y,a;
        cin>>x>>y>>a;
        a = a%(x+y);

        if(a>=x) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        

    }
    return 0;
}