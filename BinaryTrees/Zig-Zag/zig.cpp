#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        vector<vector<int>> ans;

        while (!q.empty()) {
            auto nodePair = q.front();
            q.pop();

            TreeNode* node = nodePair.first;
            int pushLevel = nodePair.second;

            if (pushLevel == ans.size())
                ans.push_back({});

            int level = pushLevel + 1;

            if (pushLevel % 2 == 0)
                ans[pushLevel].push_back(node->val);
            else
                ans[pushLevel].insert(ans[pushLevel].begin(), node->val);

            if (node->left)
                q.push({node->left, level});

            if (node->right)
                q.push({node->right, level});
        }

        return ans;
    }
};