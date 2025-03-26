#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<int> ans;
        vector<pair<int,int>> operations;

        for(int i=0;i<n;i++){
            //element zero ho
            if(arr[i]==0){
                //last element ho toh ans ka last wala nikal lenge
                if(i==n-1){
                    operations.push_back({ans.size(),ans.size()+1});
                    ans.pop_back();
                    ans.push_back(7);

                }
                
                //nahi toh current aur next ka mex aayega
                else{
                    operations.push_back({ans.size()+1,ans.size()+2});
                    ans.push_back(7);
                    i++;
                }
            }
            //non zero hai toh push kardo
            else{
                ans.push_back(7);
            }
        }
        operations.push_back({1,ans.size()});
        cout<<operations.size()<<endl;
        for(auto it:operations){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    return 0;
}