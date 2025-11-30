#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // undirected
    }

    int start;
    cin >> start;

    vector<int> dist(n, 1e9);         // large value = infinity
    dist[start] = 0;

    // min-heap: (distance, node)
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, start});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (currDist > dist[node]) continue;

        for (auto x : adj[node]) {
            int nxt = x.first;
            int wt = x.second;

            if (dist[node] + wt < dist[nxt]) {
                dist[nxt] = dist[node] + wt;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    // print final distances
    for (int i = 0; i < n; i++)
        cout << "Distance to " << i << " = " << dist[i] << endl;

    return 0;
}