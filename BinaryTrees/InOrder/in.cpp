#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution1 {
public:
    void inOrder(TreeNode* root,vector<int> &ans){
        if(root==NULL)return;
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inOrder(root,ans);
        return ans;
    }
};


class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* node = root;
        vector<int>ans;
        stack<TreeNode*>st;
        while(st.size()!=0 || node!=NULL){
            if(node != NULL){
                st.push(node);
                node=node->left;
            }
            else{
                TreeNode* temp = st.top();
                ans.push_back(temp->val);
                st.pop();
                node = temp->right;
            }
        }
        return ans;
    }
};