#include<bits/stdc++.h>
using namespace std;
//act god cat dog tac
vector<vector<string>> anagrams(vector<string>& arr) {
        
        //this is for marking if the element is visited or not
        vector<pair<string,bool>> s;
        for(int i=0;i<arr.size();i++){
            s.push_back(make_pair(arr[i],false));
        }
        vector<vector<string>> ans;
        int n = arr.size();
        for(int i=0;i<n;i++){
            vector<string> temp;
            
            //if it is visited continue
            if(s[i].second==true){
                continue;
            }
            temp.push_back(s[i].first);
           
            //storing the current element for comparison
            map<char,int> mpp1;
            for(int j=0;j<s[i].first.size();j++){
                mpp1[s[i].first[j]]++;
            }
            //marking visited
            s[i].second = true;
            
            for(int j=0;j<n;j++){
                if(s[j].second==true) continue;
                
                map<char,int> mpp2;
                for(int k=0;k<s[j].first.size();k++){
                    mpp2[s[j].first[k]]++;
                }
                
               
                
                if(mpp1==mpp2){
                     s[j].second = true;
                     temp.push_back(s[j].first);
                } 


                
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
int main(){
    vector<string> s = {"act","god","cat","dog","tac"};
    vector<vector <string > > ans = anagrams(s);
    for(int i=0;i<ans.size();i++){
       for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
       }
    }
    return 0;
}