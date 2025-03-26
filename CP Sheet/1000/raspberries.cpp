#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<int> divisible(6,0);
        for(int i=0;i<n;i++){
            if(arr[i]%3==0) divisible[3] =1;
            if(arr[i]%5==0) divisible[5] = 1;
            if(arr[i]%4==0) divisible[4] = 1;
             if(arr[i]%2==0){
                if(divisible[2]==1){
                    divisible[4] = 1;
                }
                else{
                    divisible[2] = 1;
                }

            }
        }
       
        if(divisible[k]==1){
            cout<<0<<endl;
        }
        else{
            if(k==2)cout<<1<<endl;
            else if(k==3){
                int maxi = 0;
                for(int i=0;i<n;i++){
                    maxi  = max(maxi,arr[i]%3);
                }
                cout<<3-maxi<<endl;
            }
            else if(k==5){
                int maxi = 0;
                for(int i=0;i<n;i++){
                    maxi  = max(maxi,arr[i]%5);
                }
                cout<<5-maxi<<endl;
            }
            else{
                if(divisible[2]==1){
                    cout<<1<<endl;
                }
                else{
                    int maxi = 0;
                    for(int i=0;i<n;i++){
                        maxi = max(maxi,arr[i]%4);

                    }
                    maxi = 4-maxi;
                    cout<<min(maxi,2)<<endl;
                }
            }
        }
    }
    return 0;
}