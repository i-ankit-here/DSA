#include "bits/stdc++.h"

using namespace std;

void DFS(int& time,vector<vector<int>>& graph,vector<bool>& visited,vector<char>& vertex,vector<int>& discover,vector<int>& finish,int source = 0){
    visited[source] = 1;
    discover[source] = time++;
    cout<<vertex[source]<<" ";
    int n = graph[source].size();
    for(int i = 0 ;i<n;i++){
        if(!visited[graph[source][i]])DFS(time,graph,visited,vertex,discover,finish,graph[source][i]);
    }
    finish[source] = time++;
}

int main(int argc, char const *argv[])
{
    vector<char> vertex = {'A','B','C','D','E','F','G'};
    vector<vector<int>> graph;
    vector<int> A = {1,2,3};
    vector<int> B = {0};
    vector<int> C = {0,3};
    vector<int> D = {0};
    vector<int> E = {};
    vector<int> F = {};
    vector<int> G = {};
    graph.push_back(A);
    graph.push_back(B);
    graph.push_back(C);
    graph.push_back(D);
    graph.push_back(E);
    graph.push_back(F);
    graph.push_back(G);
    vector<bool> visited(graph.size());
    vector<int> discover(graph.size());
    vector<int> finish(graph.size());
    // for(auto it:graph)for(auto i:it)cout<<i<<" ";
    int time = 1;
    for(int i = 0;i<visited.size();i++){
        if(!visited[i])DFS(time,graph,visited,vertex,discover,finish,i);
    }
    cout<<endl;
    for (int i = 0; i < graph.size(); i++)
    {
        cout<<vertex[i]<<": "<<discover[i]<<" "<<finish[i]<<endl;
    }
    
    return 0;
}
