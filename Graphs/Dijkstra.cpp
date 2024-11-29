#include "bits/stdc++.h"
using namespace std;

void BFS(vector<vector<vector<int>>> &graph,vector<char> &vertex,int source = 0){
    int n = vertex.size();
    vector<int> dist(n);
    for(int i = 0;i<n;i++){
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        for(int i = 0;i<graph[q.front()].size();i++){
            if(dist[graph[q.front()][i][0]]==INT_MAX)q.push(graph[q.front()][i][0]);
            if(dist[q.front()]+graph[q.front()][i][1]<dist[graph[q.front()][i][0]])dist[graph[q.front()][i][0]] = dist[q.front()]+graph[q.front()][i][1]; 
        }
        q.pop();
    }
    for(int i = 0;i<n;i++){
        cout<<vertex[i]<<": "<<dist[i]<<endl;
    }

}

int main(int argc, char const *argv[])
{
    vector<char> vertex = {'A', 'B', 'C', 'D', 'E'};
    vector<vector<vector<int>>> graph;
    vector<vector<int>> A = {{1,2},{2,4},{3,1}};
    vector<vector<int>> B = {{0,2},{3,1},{4,3}};
    vector<vector<int>> C = {{0,4},{3,2}};
    vector<vector<int>> D = {{0,1},{1,1},{2,2},{4,1}};
    vector<vector<int>> E = {{1,3},{3,1}};
    graph.push_back(A);
    graph.push_back(B);
    graph.push_back(C);
    graph.push_back(D);
    graph.push_back(E);
    BFS(graph,vertex,0);
    return 0;
}
