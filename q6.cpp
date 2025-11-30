#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *l, *r;
    TreeNode(int v) : val(v), l(nullptr), r(nullptr) {}
};

TreeNode* buildTree(const vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();

        if (vals[i] != -1) {
            node->l = new TreeNode(vals[i]);
            q.push(node->l);
        }
        i++;

        if (i < vals.size() && vals[i] != -1) {
            node->r = new TreeNode(vals[i]);
            q.push(node->r);
        }
        i++;
    }
    return root;
}

bool hasDuplicates(TreeNode* root) {
    unordered_set<int> seen;
    queue<TreeNode*> q;

    if (!root) return false;

    q.push(root);
    while (!q.empty()) {
        TreeNode* n = q.front(); q.pop();

        if (seen.count(n->val)) return true;
        seen.insert(n->val);

        if (n->l) q.push(n->l);
        if (n->r) q.push(n->r);
    }
    return false;
}

void freeTree(TreeNode* node) {
    if (!node) return;
    freeTree(node->l);
    freeTree(node->r);
    delete node;
}

int main() {
    int n;
    cin >> n;

    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];

    TreeNode* root = buildTree(vals);

    bool dup = hasDuplicates(root);
    cout << (dup ? "Duplicates Found" : "No Duplicates") << endl;

    freeTree(root);
    return 0;
}
