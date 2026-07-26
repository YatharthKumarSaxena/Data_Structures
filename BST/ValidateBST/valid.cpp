#include <climits>

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

// =========================
// Solution 1 : O(n²)
// =========================

class Solution {
public:
    bool isMaxTree(Node* root, int value) {
        if (!root)
            return true;

        if (root->data >= value)
            return false;

        return isMaxTree(root->left, value) &&
               isMaxTree(root->right, value);
    }

    bool isMinTree(Node* root, int value) {
        if (!root)
            return true;

        if (root->data <= value)
            return false;

        return isMinTree(root->left, value) &&
               isMinTree(root->right, value);
    }

    bool isBST(Node* root) {
        if (!root)
            return true;

        if (!isMaxTree(root->left, root->data) ||
            !isMinTree(root->right, root->data))
            return false;

        return isBST(root->left) &&
               isBST(root->right);
    }
};


// =========================
// Solution 2 : O(n)
// =========================

class Solution {
public:
    bool helper(Node* root, long long low, long long high) {
        if (!root)
            return true;

        if (root->data <= low || root->data >= high)
            return false;

        return helper(root->left, low, root->data) &&
               helper(root->right, root->data, high);
    }

    bool isBST(Node* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};