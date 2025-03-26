#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
        cin>>n>>m;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //zero hua toh check karna hi nahi hai
                if(arr[i][j]=='0') continue;


                bool flag = true;
                //upar side me check kar rahe hai
                for(int k=0;k<i;k++){
                    if(arr[k][j]=='0'){
                        flag = false;
                        break;
                    }
                }
                //koi bhi zero nahi aaya iska matlab valid hai
                if(flag) continue;
                flag = true;
                for(int k=0;k<j;k++){
                    if(arr[i][k]=='0'){
                        flag = false;
                        break;
                    }
                }
                if(!flag){
                    cout<<"NO"<<endl;
                    return ;
                }

            }
        }

        cout<<"YES"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}