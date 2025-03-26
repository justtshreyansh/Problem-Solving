#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,vector<int>> graph,int n,vector<int> &visited,int source){
    cout<<source<<" ";
    visited[source] = 1;

    for(int nbr:graph[source]){
        if(!visited[nbr]){
            dfs(graph,n,visited,nbr);
        }
    }
}

bool solve(unordered_map<int,vector<int>> graph,vector<int> &visited,int source,int parent){
    visited[source]  =1;

    for(int nbr:graph[source]){
        if(!visited[nbr]){
            bool ans = solve(graph,visited,nbr,source);
            if(ans) return true;
        }
        else if(visited[nbr]==true && parent!=nbr) return true;
    }

    return false;
}
int main(){
    vector<vector<int>> edgeList = {{1,2},{1,4},{2,3},{3,4},{5,6}};
    int n = 7;
    unordered_map<int,vector<int>> graph;
    vector<int> visited(n+1,0); 
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
            bool ans = solve(graph,visited,i,-1);
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