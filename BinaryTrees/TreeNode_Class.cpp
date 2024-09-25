#include <iostream>
using namespace std;

class TreeNode{
public:
    //Data Members
    int val;
    TreeNode* left;
    TreeNode* right;
    //Parameterized Constructor
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};