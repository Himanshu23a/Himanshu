#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    vector<pair<int,int>> items(freq.begin(), freq.end());
    sort(items.begin(), items.end());

    for (auto &p : items) {
        cout << p.first << " -> " << p.second << " times" << endl;
    }

    return 0;
}
