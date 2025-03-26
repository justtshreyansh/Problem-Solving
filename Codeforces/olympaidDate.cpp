#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        map<int,int> mpp;
        mpp[0] = 3;
        mpp[1] = 1;
        mpp[2] = 2;
        mpp[3] = 1;
        mpp[5] = 1;
        map<int,int> mpp2;
        int ans = -1;
        for(int i=0;i<n;i++){
            mpp2[arr[i]]++;
            if(mpp2[0]>=3 && mpp2[1]>=1 && mpp2[2]>=2 && mpp2[3]>=1 && mpp2[5]>=1){
                ans = i+1;
                break;
            }
        }
        if(ans==-1) cout<<0<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}