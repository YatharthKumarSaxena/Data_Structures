#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    bool checkRootExists(Node* root, int value) {
        if (!root)
            return false;

        if (root->data == value)
            return true;

        return checkRootExists(root->left, value) ||
               checkRootExists(root->right, value);
    }

    Node* lca(Node* root, int n1, int n2) {
        if (!root)
            return NULL;

        if (root->data == n1 || root->data == n2)
            return root;

        bool left1 = checkRootExists(root->left, n1);
        bool left2 = checkRootExists(root->left, n2);

        if (left1 && left2)
            return lca(root->left, n1, n2);

        if (!left1 && !left2)
            return lca(root->right, n1, n2);

        return root;
    }

    int findHeight(Node* root, int val) {
        if (!root)
            return INT_MAX;

        if (root->data == val)
            return 0;

        return 1 + min(findHeight(root->left, val),
                       findHeight(root->right, val));
    }

    int findDist(Node* root, int a, int b) {
        if (a == b)
            return 0;

        Node* checkRoot = lca(root, a, b);

        return findHeight(checkRoot, a) +
               findHeight(checkRoot, b);
    }
};