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
            return nullptr;

        if (root->data == n1 || root->data == n2)
            return root;

        if ((checkRootExists(root->left, n1) &&
             checkRootExists(root->right, n2)) ||
            (checkRootExists(root->left, n2) &&
             checkRootExists(root->right, n1)))
            return root;

        else if (checkRootExists(root->left, n1) &&
                 !checkRootExists(root->right, n2))
            return lca(root->left, n1, n2);

        else
            return lca(root->right, n1, n2);
    }
};