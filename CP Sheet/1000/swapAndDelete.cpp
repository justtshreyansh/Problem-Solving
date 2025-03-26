#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ones = 0;
        int zeros = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zeros++;
            }
            else ones++;
        }

        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(ones){
                    ones--;
                }
                else break;
            }
            else{
                if(zeros){
                    zeros--;
                }
                else break;
            }
        }
        cout<<ones+zeros<<endl;
    }
    return 0;
}