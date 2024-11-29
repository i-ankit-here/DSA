#include "bits/stdc++.h"
using namespace std;

void BFS(vector<vector<int>> graph,vector<char> vertex){
    queue<pair<int,int>> q;
    int n = vertex.size();
    vector<int> dist(n);
    for(int i = 0;i<n;i++)dist[i]=INT_MAX;
    pair<int,int> p;
    p.first = 0;p.second = 0;
    int d = 0;
    q.push(p);
    dist[p.first] = p.second;
    while (!q.empty())
    {
        for(int i = 0;i<graph[q.front().first].size();i++){
            if(dist[graph[q.front().first][i]] == INT_MAX){
                p.first =graph[q.front().first][i];
                p.second = q.front().second + 1;
                q.push(p);
            }
            if(q.front().second+1 < dist[graph[q.front().first][i]])dist[graph[q.front().first][i]]=q.front().second+1;
        }
        q.pop();
    }
    for(int i = 0;i<n;i++){
        cout<<vertex[i]<<": ";
        cout<<dist[i]<<endl;
    }    
}

int main(int argc, char const *argv[])
{
    vector<char> vertex = {'A', 'B', 'C', 'D', 'E'};
    vector<vector<int>> graph;
    vector<int> A = {1,4};
    vector<int> B = {0,2, 3};
    vector<int> C = {1,3};
    vector<int> D = {1,2,4};
    vector<int> E = {0, 3};
    vector<int> F = {};
    vector<int> G = {};
    graph.push_back(A);
    graph.push_back(B);
    graph.push_back(C);
    graph.push_back(D);
    graph.push_back(E);
    // graph.push_back(F);
    // graph.push_back(G);
    BFS(graph,vertex);
    return 0;
}
