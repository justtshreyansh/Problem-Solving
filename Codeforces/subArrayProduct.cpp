#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr,int k){
    int n = arr.size();
    vector<int> score;
    int mul = 1;
    for(int i=0;i<k;i++){
        mul*=arr[i];
    }
    score.push_back(mul);
    for(int i=k;i<n;i++){
        mul/=arr[i-k];
        mul*=arr[i];
        score.push_back(mul);
        
    }


    for(int i=0;i<score.size();i++){
        cout<<score[i]<<" ";
    }
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int k = 3;
    solve(arr,k);

    return 0;
}