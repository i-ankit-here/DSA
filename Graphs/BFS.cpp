#include "bits/stdc++.h"

using namespace std;

void BFS(vector<vector<int>>& graph,vector<char> &vertex){
    vector<bool> visited(graph.size());
    queue<int> q;
    for(int i = 0;i<visited.size();i++){
        if(visited[i])continue;
        cout<<"BFS from "<<vertex[i]<<": ";
        q.push(i); 
        while (!q.empty()){
            visited[q.front()] = 1;
            int n = graph[q.front()].size();
            for(int j = 0;j<n;j++){
                if(visited[graph[q.front()][j]])continue;
                visited[graph[q.front()][j]] = 1;
                q.push(graph[q.front()][j]);
            }
            cout<<vertex[q.front()]<<" ";
            q.pop();                        
        }   
        cout<<endl;
    }

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
    BFS(graph,vertex);
    return 0;
}
