#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> coordinates = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
void helper(int src_x,int src_y,int target_x,int target_y,int n){
    vector<vector<int>> visited(n,vector<int>(n));

    queue<pair<int,int>> q;
    q.push({src_x,src_y});
    visited[src_x][src_y] = 1;

    int steps = 0;
    while(!q.empty()){
        int qsize = q.size();
        while(qsize>0){
            pair<int,int> front = q.front();
            q.pop();
            int x = p.first;
            int y= p.second;
            if(x==target_x && y==target_y) return steps;

            for(int k=0;k<coordinates.size();k++){
                int new_x = x+coordinates[k][0];
                int new_y = y+coordinates[k][1];
                if(new_x>=0 && new_y>=0 && new_x<n && new_y<n && visited[new_x][new_y]==0){
                    visited[new_x][new_y] = 1;
                    q.push({new_x,new_y});
                }
            }
            qsize--;
        }
        steps++;
    }
}
int main(){

    
    return 0;
}