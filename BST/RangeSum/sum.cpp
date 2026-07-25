#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void sumFun(TreeNode* root,int lo,int hi,int &sum){
        if(root == NULL)return;
        sumFun(root->left,lo,hi,sum);
        if(root->val<=hi && root->val>=lo)sum += root->val;
        sumFun(root->right,lo,hi,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        sumFun(root,low,high,sum);
        return sum;
    }
};