#include<bits/stdc++.h>
using namespace std;
int optimal(vector<int> &arr){
    int mini = arr[0];
    int profit = 0;
    for(int i=1;i<arr.size();i++){
        int cost = arr[i]-mini;

        profit = max(profit,cost);

        mini = min(mini,arr[i]);
    } 
    return profit;
}
int main(){
    vector<int> arr = {7,1,5,4,3,6,4};
    cout<<optimal(arr);
    return 0;
}