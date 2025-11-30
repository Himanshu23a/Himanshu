#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<int> sa, common;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sa.insert(x);
    }

    for (int j = 0; j < m; j++) {
        int x; cin >> x;
        if (sa.count(x)) common.insert(x);
    }

    bool first = true;
    for (int v : common) {
        if (!first) cout << " ";
        cout << v;
        first = false;
    }
    cout << endl;

    return 0;
}
