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
    TreeNode* buildPreAndIn(vector<int>& preorder,int preLo,int preHi, vector<int>& inorder,int inLo,int inHi){
        if(preLo>preHi)return NULL;
        TreeNode* root = new TreeNode(preorder[preLo]);
        int in = inLo;
        int leftDis = 0;
        while(inorder[in]!=preorder[preLo]){
            in++;
        }
        leftDis = in - inLo;
        root->left = buildPreAndIn(preorder,preLo+1,preLo+leftDis,inorder,inLo,in-1+leftDis-1);
        root->right = buildPreAndIn(preorder,preLo+leftDis+1,preHi,inorder,in+1,inHi);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n1 = preorder.size();
        if(n1==0)return NULL;
        int n2 = inorder.size();
        return buildPreAndIn(preorder,0,n1-1,inorder,0,n2-1);
    }
};