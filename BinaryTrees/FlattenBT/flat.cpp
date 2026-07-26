#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;

        TreeNode* l = root->left;
        TreeNode* r = root->right;

        root->left = NULL;
        root->right = NULL;

        flatten(l);
        flatten(r);

        if (l) {
            root->right = l;

            TreeNode* temp = l;
            while (temp->right)
                temp = temp->right;

            temp->right = r;
        } else {
            root->right = r;
        }
    }
};