class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> arr;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[i].size();j++){
                    arr.push_back(grid[i][j]);
                }
            }
    
            sort(arr.begin(),arr.end());
            for(int i=0;i<arr.size();i++){
                if((arr[i]-arr[0])%x!=0) return -1;
            }
    
    
            int median = arr[arr.size()/2];
            int count = 0;
            for(int i=0;i<arr.size();i++){
    
                count+=abs((median-arr[i])/x);
            }
            return count;
    
        }
    };