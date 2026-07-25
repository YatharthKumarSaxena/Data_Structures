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
    TreeNode* buildPostAndIn(vector<int>& postorder,int postLo,int postHi, vector<int>& inorder,int inLo,int inHi){
        if(postLo>postHi)return NULL;
        TreeNode* root = new TreeNode(postorder[postHi]);
        int in = inLo;
        int leftDis = 0;
        while(inorder[in]!=postorder[postHi]){
            in++;
        }
        leftDis = in - inLo;
        root->left = buildPostAndIn(postorder,postLo,postLo+leftDis-1,inorder,inLo,in-1+leftDis-1);
        root->right = buildPostAndIn(postorder,postLo+leftDis,postHi-1,inorder,in+1,inHi);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n1 = postorder.size();
        if(n1==0)return NULL;
        int n2 = inorder.size();
        return buildPostAndIn(postorder,0,n1-1,inorder,0,n2-1);
    }
};