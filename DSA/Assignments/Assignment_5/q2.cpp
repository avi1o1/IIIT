#include <bits/stdc++.h>
using namespace std;

// Finding minimum weight path between two vertices
int minPath(int src, int dest, map<int, list<pair<int, int>>> graph) {
    // Setting up book-keeping arrays
    map<int, bool> visited;
    map<int, int> distance;

    for (auto i : graph)
        visited[i.first] = 0;
    
    for (auto i : graph)
        distance[i.first] = INT_MAX;

    // Initialising a heap structure for Dijkstra's Algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    distance[src] = 0;

    // While there are vertices to traverse
    while (!pq.empty()) {
        // Getting the minimum element
        int node = pq.top().second;
        pq.pop();

        // If node is already visited
        if (visited[node])
            continue;
        //Otherise
        else {
            // Marking node as visited
            visited[node] = true;

            // Traversing the node's neighbours
            for (auto i : graph[node]) {
                int neighbour = i.first;
                int weight = i.second;

                // If the distance to the neighbour is lower than already
                if (distance[neighbour] > distance[node] + weight) {
                    distance[neighbour] = distance[node] + weight;

                    // Adding the node to our heap
                    pq.push(make_pair(distance[neighbour], neighbour));
                }
            }
        }
    }
    // Finally, returning the minimum distance
    return distance[dest];
}

int main() {
    // Taking input
    int N, M, K;
    cin >> M >> N >> K;

    // Initialising Graph // [ ..., vertexk : [ [vertexk1, weightk1] , [vertexk2, weightk2] , ... ] , ... ]
    map<int, list<pair<int, int>>> graph;       
    
    // Taking input of normal connections
    for (int i = 0; i < N; i++) {
        // Taking edge input
        int a, b, l;
        cin >> a >> b >> l;

        // Adding undirected edge (same as bidirectional edge)
        graph[a].push_back(make_pair(b, l));
        graph[b].push_back(make_pair(a, l));
    }

    // // Printing the graph
    // for (auto i : graph) {
    //     cout << i.first << " : ";
    //     for (auto j : i.second)
    //         cout << "[" << j.first << ", " << j.second << "] ";
    //     cout << endl;
    // }

    // Comparing the fiber latencies with minimum existing latency
    int ans = 0;
    for (int j = 0; j < K; j++) {
        // Taking edge input
        int c, p;
        cin >> c >> p;

        // cout << c << " " << minPath(graph, 1, c) << endl;
        if (minPath(1, c, graph) <= p)
            ans++;

    }

    // Output
    cout << ans << endl;
    return 0;
}
