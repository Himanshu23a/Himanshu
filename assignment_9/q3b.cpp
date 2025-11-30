//prims algo
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // adjacency list: (neighbor, weight)
    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // undirected graph
    }

    // Prim's Data Structures
    vector<int> key(n, 1e9);       // weight to connect
    vector<int> parent(n, -1);     // store MST edges
    vector<bool> inMST(n, false);  // included in MST?

    // Min-heap (weight, node)
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // Start from node 0 (you can change)
    key[0] = 0;
    pq.push({0, 0});  // (weight, node)

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if (inMST[node]) continue;     // skip duplicates
        inMST[node] = true;

        for (auto &p : adj[node]) {
            int nxt = p.first;
            int wt  = p.second;

            if (!inMST[nxt] && wt < key[nxt]) {
                key[nxt] = wt;
                parent[nxt] = node;
                pq.push({key[nxt], nxt});
            }
        }
    }

    int mstCost = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " (weight = " << key[i] << ")\n";
        mstCost += key[i];
    }

    cout << "Total MST Cost = " << mstCost << endl;
    return 0;
}

