#include <iostream>
#include <vector>

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
    void findPaths(TreeNode* root, vector<int>& helper,
                   vector<vector<int>>& ans, int target) {

        if (!root) return;

        helper.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == target) {
                ans.push_back(helper);
            }
            helper.pop_back();
            return;
        }

        findPaths(root->left, helper, ans, target - root->val);
        findPaths(root->right, helper, ans, target - root->val);

        helper.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> helper;

        findPaths(root, helper, ans, targetSum);

        return ans;
    }
};