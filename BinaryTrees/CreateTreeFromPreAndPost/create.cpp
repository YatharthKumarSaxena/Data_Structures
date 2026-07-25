#include <iostream>
#include <vector>
using namespace std;

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
    TreeNode* buildPreAndPost(vector<int>& preorder,int preLo,int preHi, vector<int>& postorder,int postLo,int postHi){
        if(preLo>preHi)return NULL;
        TreeNode* root = new TreeNode(preorder[preLo]);
        if(preLo == preHi)return root;
        int leftDis = 0;
        int post = 0;
        while(postorder[post]!=preorder[preLo+1]){
            post++;
        }
        leftDis = post - postLo + 1;
        root->left = buildPreAndPost(preorder,preLo+1,preLo+leftDis,postorder,postLo,postLo+leftDis);
        root->right = buildPreAndPost(preorder,preLo+leftDis+1,preHi,postorder,post+1,postHi);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n1 = preorder.size();
        if(n1==0)return NULL;
        int n2 = postorder.size();
        return buildPreAndPost(preorder,0,n1-1,postorder,0,n2-1);
    }
};