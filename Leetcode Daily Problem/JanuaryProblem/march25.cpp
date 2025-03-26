class Solution {
    public:
        bool check (vector<vector<int>> interval){
            sort(interval.begin(),interval.end());
            
            int count = 0;
            int start = 0;
            int end = interval[0][1];
            for(int i=1;i<interval.size();i++){
                int first = interval[i][0];
                int second = interval[i][1];
    
                if(first<end){
                     
                    end = max(second,end);
                   
                    
                }
                else{
                    count++;
                    start = first;
                    end = second;
                }
            }
           
            return count>=2;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int>> first,second;
            for(int i=0;i<rectangles.size();i++){
                first.push_back({rectangles[i][0],rectangles[i][2]});
                second.push_back({rectangles[i][1],rectangles[i][3]});
            }
    
            return  check(second)|| check(first);
        }
    };