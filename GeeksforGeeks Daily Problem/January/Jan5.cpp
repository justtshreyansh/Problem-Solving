int countPairs(vector<int> &arr, int target) {
        // sort the array since we have to solve in nlog n or less complexity
        sort(arr.begin(),arr.end());
        int count =0;
        int n = arr.size();
        int i = 0;
        int j = n-1;
        
        while(i<j){
            //if the target is greater than add all elements between i and j
            if(target>arr[i]+arr[j]){
                count+=(j-i);
                i++;
            }
            else{
                j--;
            }
        }
        
        return count;
        
        
    }