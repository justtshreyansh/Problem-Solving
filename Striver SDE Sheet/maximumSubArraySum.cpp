#include<bits/stdc++.h>
using namespace std;
int bruteForce(vector<int> &arr){
    int maxi = INT_MIN;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            int sum = 0;
            for(int k=i;k<j;k++){
                sum+=arr[k];
            }
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}

int betterApproach(vector<int> &arr){
    int maxi = INT_MIN;
    for(int i=0;i<arr.size();i++){
        int sum = 0;
        for(int j=i;j<arr.size();j++){
            
            sum+=arr[j];
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}

int optimalApproach(vector<int> &arr){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];

        maxi = max(maxi,sum);
        if(sum<0) sum = 0;
    }
    return maxi;
}
int main(){
    vector<int> arr =  {-2,-3,4,-1,-2,1,6,-3};
    cout<<bruteForce(arr)<<endl;
    cout<<optimalApproach(arr)<<endl;
    return 0;
}