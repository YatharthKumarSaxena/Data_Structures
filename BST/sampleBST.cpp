// Please run all files except demoBST.cpp of BST folder in this file
// This file is a general file for execution of other files of BST folder
#include "makeYourBST.cpp"
int main(){
    cout<<"Sample BST is available\n";
    //Maing TreeNodes
    TreeNode* A = new TreeNode(10);
    TreeNode* B = new TreeNode(6);
    TreeNode* C = new TreeNode(14);
    TreeNode* D = new TreeNode(4);
    TreeNode* E = new TreeNode(8);
    TreeNode* F = new TreeNode(2);
    TreeNode* G = new TreeNode(5);
    TreeNode* H = new TreeNode(1);
    TreeNode* I = new TreeNode(3);
    TreeNode* J = new TreeNode(7);
    TreeNode* K = new TreeNode(9);
    TreeNode* L = new TreeNode(12);
    TreeNode* M = new TreeNode(17);
    TreeNode* N = new TreeNode(11);
    TreeNode* O = new TreeNode(13);
    TreeNode* P = new TreeNode(16);
    TreeNode* Q = new TreeNode(19);
    TreeNode* R= new TreeNode(18);
    TreeNode* S = new TreeNode(20);
    //Linking TreeNodes
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    D->left = F;
    D->right = G;
    F->left = H;
    F->right = I;
    E->left = J;
    E->right = K;
    C->left = L;
    C->right = M;
    L->left = N;
    L->right = O;
    M->left = P;
    M->right = Q;
    Q->left = R;
    Q->right = S;
    displayInIt(A);
}