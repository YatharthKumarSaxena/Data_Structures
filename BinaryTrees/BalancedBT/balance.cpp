#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
    int findHeight(Node* root, int level){
        if(!root)return 0;
        return 1+max(findHeight(root->left,level+1),findHeight(root->right,level+1));
    }
    bool isBalanced(Node* root) {
        // code here
        if(!root)return true;
        int leftHeight = findHeight(root->left,0);
        int rightHeight = findHeight(root->right,0);
        int diffHeight = abs(leftHeight-rightHeight);
        if(diffHeight > 1)return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};