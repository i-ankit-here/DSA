#include "bits/stdc++.h"
using namespace std;

void Dijkstra(vector<vector<vector<int>>> &graph, vector<char> &vertex, int source = 0) {
    int n = vertex.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    // Min-heap to prioritize vertices by their distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); // {distance, vertex}

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Process neighbors of u
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i][0];     // Neighbor vertex
            int weight = graph[u][i][1]; // Edge weight

            // Relaxation step
            if (currDist + weight < dist[v]) {
                dist[v] = currDist + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < n; i++) {
        cout << vertex[i] << ": " << dist[i] << endl;
    }
}

int main() {
    vector<char> vertex = {'A', 'B', 'C', 'D', 'E'};
    vector<vector<vector<int>>> graph;

    vector<vector<int>> A = {{1, 2}, {2, 4}, {3, 1}};
    vector<vector<int>> B = {{0, 2}, {3, 1}, {4, 3}};
    vector<vector<int>> C = {{0, 4}, {3, 2}};
    vector<vector<int>> D = {{0, 1}, {1, 1}, {2, 2}, {4, 1}};
    vector<vector<int>> E = {{1, 3}, {3, 1}};
    graph.push_back(A);
    graph.push_back(B);
    graph.push_back(C);
    graph.push_back(D);
    graph.push_back(E);

    Dijkstra(graph, vertex, 0);
    return 0;
}
