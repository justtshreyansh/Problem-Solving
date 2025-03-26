#include<bits/stdc++.h>
using namespace std;
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
    vector<vector<int>> edgeList = {{0,1},{1,4},{1,2},{2,3}};
    int n = 5;
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
    bfs(0,adj,n);
    return 0;

}