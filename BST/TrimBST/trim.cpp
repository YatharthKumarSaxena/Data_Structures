#include <iostream>
#include <climits>

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    void trimBST(Node* root, int lo,int hi){
        if(!root)return;
        while(root->left != NULL){
            if(root->left->data > hi){
                root->left = root->left->left;
            }
            else if(root->left->data < lo){
                root->left = root->left->right;
            }
            else break;
        }
        while(root->right != NULL){
            if(root->right->data < lo){
                root->right = root->right->right;
            }
            else if(root->right->data > hi){
                root->right = root->right->left;
            }
            else break;
        }
        trimBST(root->left,lo,hi);
        trimBST(root->right,lo,hi);
    }
    Node* removekeys(Node* root, int l, int r) {
        // code here
        Node* dummy = new Node(INT_MAX);
        dummy->left = root;
        trimBST(dummy,l,r);
        return dummy->left;
    }
};