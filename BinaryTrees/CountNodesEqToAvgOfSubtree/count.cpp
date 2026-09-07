#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


typedef pair<int,int> pip;
class Solution {
public:
    int ans = 0;
    pip giveAvgNodeValue(TreeNode* node){
        if(!node)return {0,0};
        auto [lSum,lCount] = giveAvgNodeValue(node->left);
        auto [rSum,rCount] = giveAvgNodeValue(node->right);
        int sum = lSum + rSum + node->val;
        int count = lCount + rCount + 1;
        if(node->val == sum/count)ans++;
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        giveAvgNodeValue(root);
        return ans;
    }
};