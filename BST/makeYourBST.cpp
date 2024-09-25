// Make your own Binary Search Tree
// BST is Binary Search Tree
#include "..\BinaryTrees\DisplayTree.cpp"
void insertIntoBST(int val,TreeNode* root){
    if(val<=root->val){
        if(root->left != NULL){
            insertIntoBST(val,root->left);
        }
        else{
            TreeNode* temp = new TreeNode(val);
            root->left = temp;
        }
    }
    else{
        if(val>root->val){
            if(root->right != NULL){
                insertIntoBST(val,root->right);
            }
        else{
            TreeNode* temp = new TreeNode(val);
            root->right = temp;
            }
        }
    }
}
TreeNode* makeBST(int arr[],int n){
    TreeNode* root = new TreeNode(arr[0]);
    for(int i=1;i<n;i++){
        insertIntoBST(arr[i],root);
    }
    return root;
}