#include <iostream>
#include <vector>
using namespace std;

// Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void prepareVector(Node* root, vector<int>& v) {
        if (root == NULL)
            return;

        prepareVector(root->left, v);
        v.push_back(root->data);
        prepareVector(root->right, v);
    }

    int kthSmallest(Node* root, int k) {
        vector<int> v;
        prepareVector(root, v);

        int n = v.size();

        if (k > n)
            return -1;

        return v[k - 1];
    }
};