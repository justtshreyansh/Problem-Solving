#include<bits/stdc++.h>
using namespace std;
//adjacency matrix
void adjacencyMatrix(vector<vector<int>> edgeList,int n){
    vector<vector<int>> matrix(n,vector<int> (n,0));
    for(int i=0;i<edgeList.size();i++){
        int a = edgeList[i][0];//first element
        int b = edgeList[i][1];//second element
        matrix[a][b] =1;
        matrix[b][a] = 1;//if undirected graph
    }

    for(int i=1;i<matrix.size();i++){
        for(int j=1;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void adjacencyList(vector<vector<int>> edgeList,int n){
    map<int,vector<int>> adj;
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
}

void adjacencyListWeighted(vector<vector<int>> edgeList,int n){
    map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<edgeList.size();i++){
        int a = edgeList[i][0];
        int b = edgeList[i][1];
        int c = edgeList[i][2];
        adj[a].push_back({b,c});
        adj[b].push_back({a,c}); //if undirected
    }


    for(auto i:adj){
        cout<<"Node:"<<i.first<<"->";
        for(auto j:i.second){
            cout<<j.first<<":"<<j.second<<",";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> edgeList = {{1,2,1},{2,3,2},{3,4,3},{2,4,4},{1,3,6}};
    int n = 5;
    adjacencyMatrix(edgeList,n);
    adjacencyList(edgeList,n);
    adjacencyListWeighted(edgeList,n);
    return 0;
}