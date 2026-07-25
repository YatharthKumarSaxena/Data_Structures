#include <bits/stdc++.h>
using namespace std;

// Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    Node* mirror(Node* root) {
        if (!root)
            return nullptr;

        Node* temp = root->right;
        root->right = root->left;
        root->left = temp;

        mirror(root->left);
        mirror(root->right);

        return root;
    }
};

// Inorder Traversal
void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Create Tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder Before Mirror: ";
    inorder(root);
    cout << endl;

    Solution obj;
    obj.mirror(root);

    cout << "Inorder After Mirror: ";
    inorder(root);
    cout << endl;

    return 0;
}