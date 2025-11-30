#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) { data = v; left = right = NULL; }
};

bool isBSTUtil(Node* root, int minV, int maxV) {
    if (!root) return true;
    if (root->data <= minV || root->data >= maxV) return false;
    return isBSTUtil(root->left, minV, root->data) &&
           isBSTUtil(root->right, root->data, maxV);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -1e9, 1e9);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    cout << (isBST(root) ? "YES BST" : "NOT BST") << endl;

    return 0;
}
