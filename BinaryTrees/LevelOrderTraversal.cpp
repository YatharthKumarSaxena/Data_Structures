#include "TreeNode_Class.cpp"

//* Print elements of nth level (Left to right) *//

// Through PreOrder Traversal
void displayLevelPre(TreeNode* root,int level){
    if(root == NULL){
        return;
    }
    if(level==1){
        cout<<root->val<<' ';
        return;
    }
    displayLevelPre(root->left,level-1);
    displayLevelPre(root->right,level-1);
}
// Through InOrder Traversal
void displayLevelIn(TreeNode* root,int level){
    if(root == NULL){
        return;
    }
    displayLevelIn(root->left,level-1);
    if(level==1){
        cout<<root->val<<' ';
        return;
    }
    displayLevelIn(root->right,level-1);
}
// Through PostOrder Traversal
void displayLevelPost(TreeNode* root,int level){
    if(root == NULL){
        return;
    }
    displayLevelPost(root->left,level-1);
    displayLevelPost(root->right,level-1);
    if(level==1){
        cout<<root->val<<' ';
        return;
    }
}

/* Display of a tree through 
Level Order traversal (Left to Right)*/

// Iterative Method(Best)
void displayLevelOrderTreeIt(TreeNode* root,int level){ 
    for(int i=1;i<=level;i++){
        displayLevelPre(root,i);    // Through PreOrder Traversal
        cout<<endl;
    }
    return;
}

// Pure Recursive Method
void displayLevelOrderTreeRec(TreeNode* root,int level,int i=1){
    if(root == NULL || i>level){
        return;
    }
    displayLevelPre(root,i);    // Through PreOrder Traversal
    cout<<endl;
    displayLevelOrderTreeRec(root,level,i+1);
}

//* Print elements of nth level (Right to left) *//

/* To use inorder traversal replace 
displayLevelPreRev by displayLevelInRev
//To use postorder traversal replace 
displayLevelPreRev by displayLevelPostRev*/
void displayLevelPreRev(TreeNode* root,int level){  // Through Preorder Traversal
    if(root == NULL){
        return;
    }
    if(level==1){
        cout<<root->val<<' ';   
        return;
    }
    displayLevelPreRev(root->right,level-1);
    displayLevelPreRev(root->left,level-1);
}
// Through InOrder Traversal
void displayLevelInRev(TreeNode* root,int level){  // Through Preorder Traversal
    if(root == NULL){
        return;
    }
    displayLevelInRev(root->right,level-1);
    if(level==1){
        cout<<root->val<<' ';   
        return;
    }
    displayLevelInRev(root->left,level-1);
}
// Through PostOrder Traversal
void displayLevelPostRev(TreeNode* root,int level){  // Through Preorder Traversal
    if(root == NULL){
        return;
    }
    displayLevelPostRev(root->right,level-1);
    displayLevelPostRev(root->left,level-1);
    if(level==1){
        cout<<root->val<<' ';   
        return;
    }
}

/* Display of a tree through 
Level Order traversal (Right to Left) */

// Iterative method(Best)

/* To use inorder traversal 
replace displayLevelPreRev by displayLevelInRev
// To use postorder traversal 
replace displayLevelPreRev by displayLevelPostRev */
void displayLevelOrderTreeItRev(TreeNode* root,int level){
    for(int i=1;i<=level;i++){ 
        displayLevelPreRev(root,i); // Through PreOrder Traversal
        cout<<endl;
    }
    return;
}

// Pure Recursive Method

/* To use inorder traversal 
replace displayLevelPreRev by displayLevelInRev
// To use postorder traversal 
replace displayLevelPreRev by displayLevelPostRev */
void displayLevelOrderTreeRecRev(TreeNode* root,int level,int i=1){
    if(root == NULL || i>level){
        return;
    }
    displayLevelPreRev(root,i); // Through PreOrder Traversal
    cout<<endl;
    displayLevelOrderTreeRecRev(root,level,i+1);
}