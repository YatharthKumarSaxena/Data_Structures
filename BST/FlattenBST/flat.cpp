#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    void makePreOrder(Node* root,vector<Node*>& ans){
        if(!root)return;
        makePreOrder(root->left,ans);
        ans.push_back(root);
        makePreOrder(root->right,ans);
    }
    Node *flattenBST(Node *root) {
        // code here
        if(!root)return NULL;
        vector<Node*>nodes;
        makePreOrder(root,nodes);
        int n = nodes.size();
        for(int i=0;i<n-1;i++){
            nodes[i]->right = nodes[i+1];
            nodes[i]->left = NULL;
        }
        nodes[n-1]->right = NULL;
        nodes[n-1]->left = NULL;
        return nodes[0];
    }
};