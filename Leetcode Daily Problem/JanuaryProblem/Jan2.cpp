class Solution {
public:
    bool vowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
   
    //optimal approach
    vector<int> optimalApproach(vector<string>& words, vector<vector<int>>& queries){
        int n = words.size();
        //using prefix sum  for storing the count of vowels words
        vector<int> prefix(n+1,0);
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            string str= words[i];
            int start = 0;
            int end = str.size()-1;
            prefix[i+1] = prefix[i];
            if(vowel(str[start]) && vowel(str[end])){
               prefix[i+1]++;
            }
         
        }
        //querying
        for(int i=0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
        
            ans.push_back(prefix[right+1]-prefix[left]);
            
        }
        return ans;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        return optimalApproach(words,queries);
    }
};