#include "bits/stdc++.h"
using namespace std;

void DFS(vector<vector<int>> &graph,vector<bool>& visited,stack<int>& st, int source)
{
    for (int j = 0; j < graph[source].size(); j++)
    {
        if(visited[graph[source][j]])continue;
        visited[graph[source][j]] = 1;
        DFS(graph,visited,st,graph[source][j]);
    }
    st.push(source);
}

void topo_sort_DFS(vector<vector<int>> &graph, vector<char> &vertex)
{
    int n = vertex.size();
    vector<bool> visited(n);
    stack<int> st;
    for (int i = 0; i < n; i++){
        if(visited[i])continue;
        DFS(graph,visited,st,i);
    }
    while(!st.empty()){
        cout<<vertex[st.top()]<<" ";
        st.pop();
    }
}

void topo_sort_kahn(vector<vector<int>> &graph, vector<char> &vertex)
{
    int n = vertex.size();
    // vector<bool> visited(n);
    queue<int> q;
    vector<int> indegree(n);
    for (auto it : graph)
        for (auto i : it)
            indegree[i]++;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int temp = q.front();
        // visited[temp] = 1;
        for (int i = 0; i < graph[temp].size(); i++)
            if (--indegree[graph[temp][i]] == 0)
                q.push(graph[temp][i]);
        q.pop();
        cout << vertex[temp] << " ";
    }
}

int main(int argc, char const *argv[])
{
    vector<char> vertex = {'A', 'B', 'C', 'D', 'E'};
    vector<vector<int>> graph;
    vector<int> A = {1, 3, 4};
    vector<int> B = {2, 3};
    vector<int> C = {};
    vector<int> D = {2};
    vector<int> E = {1, 3};
    vector<int> F = {};
    vector<int> G = {};
    graph.push_back(A);
    graph.push_back(B);
    graph.push_back(C);
    graph.push_back(D);
    graph.push_back(E);
    // graph.push_back(F);
    // graph.push_back(G);
    topo_sort_DFS(graph, vertex);
    cout << endl;
    topo_sort_kahn(graph, vertex);
    return 0;
}
