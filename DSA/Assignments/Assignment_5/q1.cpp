#include <bits/stdc++.h>
using namespace std;

// DFS traversal of the vertices
void DFS(map<int, list<int>>& adj, map<int, bool>& visited, int v) {
    // Mark the current node as visited
    visited[v] = true;

    // Recursive call to successive nodes
    for (int i : adj[v])
        if (!visited[i])
            DFS(adj, visited, i);
}

int main() {
    // Taking input
    int N, M;
    cin >> M >> N;

    // Initialisation and Creation of graph
    map<int, list<int>> adj;
    for (int j = 0; j < N; j++) {
        // Taking edge input
        int x, y;
        cin >> x >> y;

        // Adding undirected edge (same as bidirectional edge)
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Initialising variables and arrays
    int ans = 0;
    int idx = 0;
    map<int, int> components;
    map<int, bool> visited;
    for (int i = 0; i < M; i++)
        visited[i+1] = 0;

    // DFS traversal for each unconnected component
    for (int k = 0; k < M; k++) {
        // cout << k+1 << " " << visited[k+1] << "\n";
        if (visited[k+1] == 0) {
            components[idx++] = k+1;
            ans++;
            DFS(adj, visited, k+1);
        }
    }

    // Output
    cout << ans-1 << endl;
    for (int x = 1; x < idx; x++)
        cout << components[0] << " " << components[x] << endl;

    return 0;
}
