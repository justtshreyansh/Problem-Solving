class Solution {
  public:
    int countSubarrays(vector<int> &nums, int k) {
        // code here
        map<int,int> mpp;
        int sum = 0;
        int rem =0;
        int ans =0;
        //edge case if the element itself is equal to k then the remaining should be zero so we have to add 1
        mpp[0] =1;
        for(int i=0;i<nums.size();i++){
            //adding the current element 
            sum+=nums[i];
            //calculating the required number
            rem = sum- k;
            //if the required number is already existed then we add the occurence in our ans
            ans+=mpp[rem];
            //pushing the value of sum 
            mpp[sum]++;
        }
        return ans;
    }
};