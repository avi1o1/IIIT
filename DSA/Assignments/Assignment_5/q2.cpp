#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int findAns(vector<vector<vector<ll>>> &graph, int vertexCount) {
    // Initialising min-heap for Dijkstra's Algorithm
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push(make_pair(0, 1));

    // Initialising distance array
    vector<ll> dist(vertexCount+1, INT_MAX);
    vector<int> opt(vertexCount+1, 0);
	dist[1] = 0;

	// While there are vertices to traverse
    int ans = 0;
	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();

		for (auto i : graph[node]) {
            // Extracting node info
			int edgeEnd = i[0];
			ll weight = i[1];
            int isFiber = i[2];

			// If there is shorted path to v through u.
			if (dist[edgeEnd] > dist[node] + weight) {
				// Updating distance of v
				dist[edgeEnd] = dist[node] + weight;
				pq.push({dist[edgeEnd], edgeEnd});

                if (opt[edgeEnd] == 1) {
                    ans--;
                    opt[edgeEnd] = 0;
                    // cout << edgeEnd << " : " << dist[edgeEnd] << "\n";
                }

                if (isFiber) {
                    ans++;
                    opt[edgeEnd] = 1;
                    // cout << edgeEnd << " : " << dist[edgeEnd] << "\n";
                }
			}

            else if (dist[edgeEnd] == dist[node] + weight && !isFiber && opt[edgeEnd]) {
                // cout << dist[edgeEnd] << " " << dist[node] << " " << weight << " " << isFiber << " " << opt[edgeEnd] << "\n";
                ans--;
                opt[edgeEnd] = 0;
                // cout << edgeEnd << " : " << dist[edgeEnd] << "\n";
            }
		}
	}

    // printing distance array
    // for (int i = 0; i < vertexCount; i++) {
    //     cout << i+1 << " : " << dist[i+1] << "\n";
    // }

    // cout << ans << "\n";
    return ans;
}

int main() {
    // Taking input
    int edgeCount, vertexCount, opticals;
    cin >> vertexCount >> edgeCount >> opticals;

    // Initialising Graph [ edgeStart : { (edgeEnd, edgeWeight), ... } ]
    vector<vector<vector<long long int>>> graph(vertexCount+1);
    
    // Taking input of normal connections
    for (int i = 0; i < edgeCount; i++) {
        // Taking edge input
        long long int a, b, l;
        cin >> a >> b >> l;

        // Adding edges to graph [ 0 : Normal connection ]
        graph[a].push_back({b, l, 0});
        graph[b].push_back({a, l, 0});
    }

    // Taking input of fiber connections
    for (int i = 0; i < opticals; i++) {
        // Taking edge input
        long long int c, k;
        cin >> c >> k;

        // Adding edges to graph [ 1 : Fiber connection ]
        graph[1].push_back({c, k, 1});
        graph[c].push_back({1, k, 1});
    }

    // Printing Graph
    // for (int i = 0; i < vertexCount; i++) {
    //     cout << i << " : ";
    //     for (int j = 0; j < graph[i].size(); j++) {
    //         cout << "[" << graph[i][j][0] << ", " << graph[i][j][1] << ", " << graph[i][j][2] << "], ";
    //     }
    //     cout << "\n";
    // }

    // Step-Djikstra's Algorithm
    cout << opticals - findAns(graph, vertexCount) << "\n";

	return 0;
}
