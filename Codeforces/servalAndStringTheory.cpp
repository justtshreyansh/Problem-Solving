#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;

    //universal lasrevinu
    while(t--){
        int n,k;
        cin>>n>>k;
        string rev;
        cin>>rev;
        string str = rev;
        reverse(rev.begin(),rev.end());
        bool flag = false;
        
        if(rev>str) flag = true;
        else if(rev<str){
            int i = 0;
            int j = str.size()-1;
            
            while(i<j){
                //pahle wala bada hai
                if(str[i]>str[j]){
                    if(k>0){
                        flag = true;
                        break;
                       
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                //pahle wala chota hai
                else if(str[i]<str[j]){
                    flag = true;
                    break;
                }
                else{
                  
                }
                i++;
                j--;
                
               
            }
        }
        else{
            
           map<char,int> mpp;
           for(int i=0;i<str.size();i++){
               mpp[str[i]]++;
           }
           for(auto it:mpp){
               if(it.second!=str.size() && k!=0){
                   
                   flag = true;
                   break;
               }
           }
            
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}