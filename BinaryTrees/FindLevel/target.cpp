#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    int getTargetLevel(struct Node *node, int target,int level){
        if(!node)return -1;
        if(node->data == target)return level;
        return max(getTargetLevel(node->left,target,level+1),getTargetLevel(node->right,target,level+1));
    }
    int getLevel(struct Node *node, int target) {
        // code here
        return 1+getTargetLevel(node,target,0);
    }
};