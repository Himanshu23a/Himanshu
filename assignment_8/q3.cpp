#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) { data = v; left = right = NULL; }
};

Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else if (val > root->data) root->right = insertBST(root->right, val);
    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteBST(Node* root, int key) {
    if (!root) return NULL;
    if (key < root->data) root->left = deleteBST(root->left, key);
    else if (key > root->data) root->right = deleteBST(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        Node* succ = findMin(root->right);
        root->data = succ->data;
        root->right = deleteBST(root->right, succ->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (!root) return 0;
    int L = minDepth(root->left);
    int R = minDepth(root->right);
    if (!root->left || !root->right)
        return 1 + L + R;
    return 1 + min(L, R);
}

int main() {
    Node* root = NULL;
    root = insertBST(root, 20);
    insertBST(root, 10);
    insertBST(root, 30);
    insertBST(root, 25);

    root = deleteBST(root, 10);

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    return 0;
}
