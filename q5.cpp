#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

int main() {
    int n;
    cin >> n;

    vector<ListNode*> nodes;

    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        nodes.push_back(new ListNode(v));
        if (i > 0) nodes[i-1]->next = nodes[i];
    }

    int pos;
    cin >> pos;

    if (pos >= 0 && pos < n)
        nodes.back()->next = nodes[pos];

    unordered_set<ListNode*> seen;
    ListNode* cur = nodes[0];
    bool hasCycle = false;

    while (cur) {
        if (seen.count(cur)) {
            hasCycle = true;
            break;
        }
        seen.insert(cur);
        cur = cur->next;
    }

    cout << (hasCycle ? "true" : "false") << endl;

    if (pos == -1)
        for (auto p : nodes) delete p;

    return 0;
}
