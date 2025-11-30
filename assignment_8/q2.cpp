#include <iostream>
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
    else root->right = insertBST(root->right, val);
    return root;
}

// Recursive search
Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// Non-recursive search
Node* searchNonRec(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* target = searchRec(root, key);
    if (!target) return NULL;

    if (target->right)
        return findMin(target->right);

    Node* succ = NULL;
    Node* curr = root;
    while (curr != target) {
        if (key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* target = searchRec(root, key);
    if (!target) return NULL;

    if (target->left)
        return findMax(target->left);

    Node* pred = NULL;
    Node* curr = root;
    while (curr != target) {
        if (key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = insertBST(root, 20);
    insertBST(root, 10);
    insertBST(root, 30);
    insertBST(root, 5);
    insertBST(root, 15);

    cout << "Searching 15: " 
         << (searchRec(root, 15) ? "Found" : "Not Found") << endl;

    cout << "Max: " << findMax(root)->data << endl;
    cout << "Min: " << findMin(root)->data << endl;

    cout << "Successor of 15: " 
         << inorderSuccessor(root, 15)->data << endl;

    cout << "Predecessor of 15: " 
         << inorderPredecessor(root, 15)->data << endl;

    return 0;
}
