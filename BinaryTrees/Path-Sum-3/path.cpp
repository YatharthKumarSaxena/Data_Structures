#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int findPaths(TreeNode* root, long long target) {
        if (!root)
            return 0;

        int count = (target == root->val) ? 1 : 0;

        return findPaths(root->left, target - root->val) +
               findPaths(root->right, target - root->val) +
               count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;

        return findPaths(root, targetSum) +
               pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};