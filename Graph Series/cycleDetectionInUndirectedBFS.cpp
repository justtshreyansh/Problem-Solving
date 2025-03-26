#include<bits/stdc++.h>
using namespace std;



bool bfs(unordered_map<int,vector<int>> graph,vector<int> &visited,vector<int> &parent,int source){
    queue<int> q;
    q.push(source);
    visited[source] =1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int nbr:graph[front]){
            if(!visited[nbr]){
                visited[nbr]=1;
                parent[nbr] = front;
                q.push(nbr);
            }
            else{
                if(parent[front]!=nbr) return true;
            }
        }
    }
}
int main(){
    vector<vector<int>> edgeList = {{1,2},{1,4},{2,3},{3,4},{5,6}};
    int n = 7;
    unordered_map<int,vector<int>> graph;
    vector<int> visited(n+1,0); 
    vector<int> parent(n+1,-1);
    for(int i=0;i<edgeList.size();i++){
        int a = edgeList[i][0];
        int b = edgeList[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(auto i:graph){
        cout<<"Node:"<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    bool flag = false;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool ans = bfs(graph,visited,parent,i);
            if(ans){
                flag = true;
                break;
            }

        }
    }
    if(flag) cout<<"Cycle detected"<<endl;
    else cout<<"Cycle not found"<<endl;
    return 0;
}