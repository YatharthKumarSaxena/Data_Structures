#include "TreeNode_Class.cpp"
#include <climits>

//Note:- 1.) You can test these functions in demoTree.cpp file 
// 2.) In that file a demo tree along with int main function is available to check these codes

// Total number of levels in a tree
int totalLevelTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1+max(totalLevelTree(root->left),totalLevelTree(root->right));
}

// Height of a Tree
int heightOfTree(TreeNode* root){
    int level = totalLevelTree(root);
    return level-1;
}
// Sum of all Tree Nodes
int sumAllTreeNode(TreeNode* root){
    if(root == NULL)return 0;
    int leftSum = sumAllTreeNode(root->left);
    int rightSum = sumAllTreeNode(root->right);
    int ans = root->val + leftSum + rightSum;
    return ans;
}

//Product of all Tree Nodes
int productAllTreeNodes(TreeNode* root){
    if(root == NULL)return 1;
    int leftProd = productAllTreeNodes(root->left);
    int rightProd = productAllTreeNodes(root->right);
    return root->val*leftProd*rightProd;
}

// Size of Tree i.e Total number of nodes in a tree
int sizeTree(TreeNode* root){
    if(root==NULL)return 0;
    int leftNodes = sizeTree(root->left);
    int rightNodes = sizeTree(root->right);
    int size = 1 + leftNodes + rightNodes;
    return size;
}

//Node with maximum value in a tree
int maxTreeNode(TreeNode* root){
    if(root == NULL){
        return INT_MIN;
    }
    int rightMax = maxTreeNode(root->right);
    int leftMax = maxTreeNode(root->left);
    return max(root->val,max(leftMax,rightMax));
}

//Node with minimum value in a tree
int minTreeNode(TreeNode* root){
    if(root==NULL){
        return INT_MAX;
    }
    int leftMin = minTreeNode(root->left);
    int rightMin = minTreeNode(root->right);
    return min(root->val,min(leftMin,rightMin));
}
