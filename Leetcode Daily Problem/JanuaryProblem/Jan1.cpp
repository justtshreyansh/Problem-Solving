class Solution {
public:
    int BruteForce(string s){
        int ans = -1;
        for(int i=1;i<s.size();i++){
            //for counting the zeroes in the left part
           int leftZero = 0;
           
           for(int j=0;j<i;j++){
                if(s[j]=='0') leftZero++;

           }
            //for counting the ones in the right part
           int rightOne = 0;
           for(int j=i;j<s.size();j++){
            if(s[j]=='1') rightOne++;
           }

           ans = max(ans,leftZero+rightOne);
        }
        return ans;
    }
    int optimalApproach(string s){
        int ones = 0;
        int ans = -1;
        int zeros = 0;
        //we are counting the number of ones in the string
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') ones++;
        }
        //here if we encounter zero we add up and if we encounter ones than we reduce onecount by 1
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0') zeros++;
            else ones--;
            ans = max(ans,zeros+ones);
        }
        return ans;
    }
    int maxScore(string s) {
        return optimalApproach(s);
    }
};