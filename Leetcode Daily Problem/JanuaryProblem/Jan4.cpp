class Solution {
public:
    //since we have to find the palidrome of 3 size so if the last and first are equal then we can put any element between them.
    int countPalindromicSubsequence(string s) {
        map<char,int> mpp;

        //storing unique characters
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int count =0;
        //for every unique charcter find the first and last index of occurence
        for(auto it:mpp){
            int first = -1;
            int last = -1;
            for(int i=0;i<s.size();i++){
                if(it.first==s[i]){
                    if(first==-1){
                        first = i;
                    }
                    last = i;
                }
            }
            //if they occur once skip it
            if(first==last) continue;
            map<char,int> mpp2;
            //othwerwise count the total unique number between the character
            for(int i=first+1;i<last;i++){
                mpp2[s[i]]++;
            }
            count+=mpp2.size();
        }
        return count;
    }
};