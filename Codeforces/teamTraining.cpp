#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> arr;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        //1 2 3 3 6 1
        sort(arr.begin(),arr.end());
        int index = 0;
        
        //kitne elements equal ya bade hai
        for(int i=0;i<n;i++){
            if(arr[i]>=x){
                index = i;
                break;
            }
        }
        //baaki jo bhi hai index ke pahle wala usko minimum se multiply karo
        int mul = index * arr[0];
        if(mul>=x) cout<<n-index+1<<endl;
        else cout<<n-index<<endl;
    }
    return 0;
}