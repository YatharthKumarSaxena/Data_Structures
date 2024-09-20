#include "TreeNode_Class.cpp"
#include <queue>

// Note:- Please run this file in demoTree.cpp.
// Because int main function along with tree is available there

// To print each level of Tree in normal order i.e from left to right
void BFS_Traversal(TreeNode* root){
    queue<TreeNode*>q;
    if(root == NULL)return;
    q.push(root);
    while(q.size()){
        TreeNode* ele = q.front();
        q.pop();
        cout<<ele->val<<' ';
        if(ele->left){
            q.push(ele->left);
        }
        if(ele->right){
            q.push(ele->right);
        }
    }
}

// To print each level of Tree in reverse order i.e from right to left
void BFS_TraversalRev(TreeNode* root){
    queue<TreeNode*>q;
    if(root == NULL)return;
    q.push(root);
    while(q.size()){
        TreeNode* ele = q.front();
        q.pop();
        cout<<ele->val<<' ';
        if(ele->right){
            q.push(ele->right);
        }
        if(ele->left){
            q.push(ele->left);
        }
    }
}