#include <bits/stdc++.h>
using namespace std;

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
    TreeNode* buildTree(vector<TreeNode*>& nodeList) {

        int n = nodeList.size();

        if (n == 0)
            return nullptr;

        queue<TreeNode*> qu;

        TreeNode* root = nodeList[0];
        qu.push(root);

        int i = 1;
        int j = 2;

        while (!qu.empty() && i < n) {

            TreeNode* node = qu.front();
            qu.pop();

            TreeNode* leftNode = nullptr;
            TreeNode* rightNode = nullptr;

            if (nodeList[i])
                leftNode = nodeList[i];

            if (j < n && nodeList[j])
                rightNode = nodeList[j];

            if (leftNode)
                qu.push(leftNode);

            if (rightNode)
                qu.push(rightNode);

            node->left = leftNode;
            node->right = rightNode;

            i += 2;
            j += 2;
        }

        return root;
    }
};