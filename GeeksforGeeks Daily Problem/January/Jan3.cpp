long subarrayXor(vector<int> &nums, int k) {
        // code here
        
        map<int,int> mpp;
        long long sum = 0;
        long long rem =0;
        long long ans =0;
    
        mpp[0] =1;
        for(int i=0;i<nums.size();i++){
          
            sum^=nums[i];
          
            rem = sum^ k;
        
            ans+=mpp[rem];
    
            mpp[sum]++;
        }
        return ans;
    }