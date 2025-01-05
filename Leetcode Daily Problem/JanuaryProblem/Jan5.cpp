#include<bits/stdc++.h>
using namespace std;
string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //prefix 
        vector<int> shift(s.size()+1,0);
        //here we are calculation prefix or difference 
        for(int i=0;i<shifts.size();i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];
            
            shift[start]+=(direction==1?1:-1);
            shift[end+1]-=(direction==1?1:-1);
            
        }
       
        //finding cumulative sum
        int currentSum =0;
        for(int i=0;i<s.size();i++){
            currentSum+=shift[i];
            shift[i] = currentSum;
        }

        
        //just adding the values 
        for(int i=0;i<s.size();i++){
            int net = (shift[i]%26+26)%26;
            s[i] = 'a' + (s[i]-'a'+net) %26;
        }

        return s;
    }
int main(){
    vector<vector<int>> matrix = {{0,1,0},{1,2,1},{0,2,1}};
    cout<<shiftingLetters("abc",matrix);
    return 0;
}