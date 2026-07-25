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
    bool checkPath(TreeNode* root, long long target) {
        if (!root)
            return false;

        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == target)
                return true;
            return false;
        }

        return checkPath(root->left, target - root->val) ||
               checkPath(root->right, target - root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkPath(root, targetSum);
    }
};