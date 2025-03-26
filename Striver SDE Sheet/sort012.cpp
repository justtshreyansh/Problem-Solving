#include<bits/stdc++.h>
using namespace std;
void bruteForce(vector<int> &arr){
    sort(arr.begin(),arr.end());
}

void betterSolution(vector<int> &arr){
    int count0= 0;
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0) count0++;
        else if(arr[i]==1) cnt1++;
        else cnt2++;

    }
    for(int i=0;i<count0;i++){
        arr[i] = 0;
    }
    for(int i=count0;i<count0+cnt1;i++){
        arr[i] = 1;
    }
    for(int i=count0+cnt1;i<arr.size();i++){
        arr[i] =2;
    }
}

void dutchNationalFlagAlgorithm(vector<int> &arr){
    int mid = 0;
    int low = 0;
    int high = arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<int> arr = {0,1,2,0,1,2,0,1,2};
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // bruteForce(arr);
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // betterSolution(arr);
    dutchNationalFlagAlgorithm(arr);
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    return 0;
}