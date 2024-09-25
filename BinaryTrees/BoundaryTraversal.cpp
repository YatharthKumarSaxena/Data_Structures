//Note :- In array , value will represent the value of TreeNode 
//Note :- In array , INT_MIN will represent the value of NULL.


#include "TreeNode_Class.cpp"
#include <climits>
#include <queue>
int totalLevelTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1+max(totalLevelTree(root->left),totalLevelTree(root->right));
}
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
void displayLevelOrderTreeIt(TreeNode* root,int level){ 
    for(int i=1;i<=level;i++){
        displayLevelPre(root,i);    // Through PreOrder Traversal
        cout<<endl;
    }
    return;
}
TreeNode* constructTree(int arr[],int n){
    if(n==0)return NULL;
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*>q;
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size() && i<n){
        TreeNode* temp = q.front();
        q.pop();
        TreeNode* l;
        TreeNode* r;
        if(arr[i]!=INT_MIN){
            l = new TreeNode(arr[i]);
        }
        else{
            l = NULL;
        }
        if(j<n && arr[j]!=INT_MIN){
            r = new TreeNode(arr[j]);
        }
        else{
            r = NULL;
        }
        temp->left = l;
        temp->right = r;
        if(l)q.push(l);
        if(r)q.push(r);
        i += 2;
        j += 2;
    }
    return root;
}
void bottomBoundary(TreeNode* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        cout<<root->val<<' ';
        return;
    }
    bottomBoundary(root->left);
    bottomBoundary(root->right);
}
// Iterative Approach
void leftBoundaryIt(TreeNode* root){
    if(root == NULL){
        return;
    }
    while(root->left != NULL && root->right != NULL){
        while(root->left){
            cout<<root->val<<' ';
            root = root->left;
        }
        if(root->right){
            cout<<root->val<<' ';
            root = root->right;
        }
    }
}
// Recursive Approach
void leftBoundaryRec(TreeNode* root){
    if(root == NULL ){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    cout<<root->val<<' ';
    if(root->left){
        leftBoundaryRec(root->left);
    }
    else if(root->right && root->left == NULL){
        leftBoundaryRec(root->right);
    }
}
void rightBoundary(TreeNode* root){
    if(root == NULL ){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(root->right){
        rightBoundary(root->right);
    }
    else if(root->left && root->right == NULL){
        rightBoundary(root->left);
    }
    cout<<root->val<<' ';
}
void boundaryTraversal(TreeNode* root){
    leftBoundaryIt(root);
    bottomBoundary(root);
    rightBoundary(root->right);
}
int main(){
    cout<<"Welcome to the world of C++ Programming\n";
    cout<<"To print the boundary traversal of a tree by a given array\n";
    int arr[] = {1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    int n = sizeof(arr)/4;
    TreeNode* root = constructTree(arr,n);
    int levelOfTree = totalLevelTree(root);
    cout<<"Default tree in this program as per level order looks like :- \n";
    displayLevelOrderTreeIt(root,levelOfTree);
    cout<<"View of the tree or boundary Traversal of Tree looks like :-\n";
    boundaryTraversal(root);
}