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

void bfs(int source,unordered_map<int,vector<int>>graph,int n){
    queue<int> q;
    //pushing the source node
    q.push(source);

    vector<int> visited(n+1,0);
    //marking the source node visited
    visited[source] = 1;

    while(!q.empty()){
        //extracting the front element
        int f  = q.front();
        q.pop();
        cout<<f<<" "; //printing the element
        for(int nbr:graph[f]){ //extracting the neighbour of the extracted element
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = 1;
            }
        }
    }
}
int main(){
    vector<vector<int>> edgeList = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    int n = 6;
    int source = 0;
    int destination = 5;
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
    dfs(source,adj,n,visited);
    if(visited[destination]){
        cout<<"Path is possible "<<endl;
    }
    else{
        cout<<"Path is not possible"<<endl;
    }
    return 0;
}