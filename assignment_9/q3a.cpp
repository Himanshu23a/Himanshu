//kruksal algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int v, vector<int> &parent) {
    if (v == parent[v]) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);

    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
        return a.w < b.w;
    });

    vector<int> parent(n), rank(n, 0);

    // Initially every node is its own parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int mstCost = 0;
    vector<Edge> mst;

    for (auto &e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);

        if (pu != pv) {
            mst.push_back(e);
            mstCost += e.w;
            unionSet(pu, pv, parent, rank);
        }
    }

    cout << "Edges in MST:\n";
    for (auto &e : mst)
        cout << e.u << " - " << e.v << " (" << e.w << ")\n";

    cout << "Total MST Cost = " << mstCost << endl;

    return 0;
}

