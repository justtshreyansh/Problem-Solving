#include<bits/stdc++.h>
using namespace std;
//1 2 3
void bruteForce(vector<int> arr , vector<vector<int>> &ans,int index){
    if(index==arr.size()){
        ans.push_back(arr);
        return ;
    }

    for(int i=index;i<arr.size();i++){

        swap(arr[index],arr[i]);
        bruteForce(arr,ans,index+1);
        swap(arr[index],arr[i]);

    }
}

void betterSolution(vector<int> &arr){
    next_permutation(arr.begin(),arr.end());
    
}

// 2 1 5 4 3 0 0 
vector<int> optimal(vector<int> &arr){
    int n = arr.size();
    //find the index where a[i] < a[i+1]
    int index = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index = i;
            break;
        }
    }
    //check if the array is sorted then return the reverse of the array
    if(index==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }
    //swap the index element with the just bigger element
    for(int i=n-1;i>=index;i--){
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }

    

    
    index+=1;
    reverse(arr.begin()+index,arr.end());
    return arr;
}
int main(){
    vector<int> arr = {1,2,3};
    // vector<vector<int>> ans;
    // int index = 0;
    // betterSolution(arr);
    vector<int> ans = optimal(arr);
    for(int i=0;i<arr.size();i++){
        cout<<ans[i]<<" ";
    }
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}