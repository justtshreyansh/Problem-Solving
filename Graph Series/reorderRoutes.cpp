#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,vector<int>> forward,unordered_map<int,vector<int>> backward,int n,int &ans,vector<int> &visited,int source){
    visited[source] = 1;

    for(int nbr:forward[source]){
        if(!visited[nbr]){
            ans+=1;
            dfs(forward,backward,n,ans,visited,nbr);
        }
    }

    for(int nbr:backward[source]){
        if(!visited[nbr]){
            dfs(forward,backward,n,ans,visited,nbr);
        }
    }
}

int bfs(unordered_map<int,vector<int>> forward,unordered_map<int,vector<int>> backward,int n,vector<int> &visited,int source){
    int ans = 0;
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int nbr:forward[front]){
            if(!visited[nbr]){
                q.push(nbr);
                ans+=1;
                visited[nbr] =1;
            }
        }

        for(int nbr:backward[front]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]  =1;
            }
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> edgeList = {{1,0},{1,2},{3,2},{3,4}};
    int n = 5;
    unordered_map<int,vector<int>> forward,backward;
        for(int i=0;i<connections.size();i++){
            int a = connections[i][0];
            int b = connections[i][1];

            forward[a].push_back(b);
            backward[b].push_back(a);
        }
        vector<int> visited(n,0);
        int ans = 0;
        int source = 0;
        bfs(forward,backward,n,visited,source);
    return 0;
}