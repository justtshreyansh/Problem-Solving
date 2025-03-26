#include<bits/stdc++.h>
using namespace std;
void dfs(int source,unordered_map<int,vector<int>> graph,int n,vector<int> &visited){
    //printing the source node
    cout<<source<<" ";
    visited[source] = 1;
    //iterating over the adjacent elements
    for(int nbr:graph[source]){
        if(!visited[nbr]){
            dfs(nbr,graph,n,visited);//if not visited then doing dfs over them.
            
        }
    }
}
int main(){
    vector<vector<int>> edgeList = {{0,1},{1,4},{1,2},{2,3}};
    int n = 5;
    vector<int> visited(n+1,0);
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edgeList.size();i++){
        int a = edgeList[i][0];
        int b = edgeList[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a); //if undirected
    }


    for(auto i:adj){
        cout<<"Node:"<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<",";
        }
        cout<<endl;
    }
    dfs(0,adj,n,visited);
    return 0;
}