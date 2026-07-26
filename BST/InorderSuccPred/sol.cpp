#include <iostream>
#include <vector>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    void prepareInVector(Node* root,vector<Node*>& ans){
        if(!root)return;
        prepareInVector(root->left,ans);
        ans.push_back(root);
        prepareInVector(root->right,ans);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*>check;
        prepareInVector(root,check);
        int n = check.size();
        Node* pred = NULL;
        Node* succ = NULL;
        for(int i=0;i<n;i++){
            int val = check[i]->data;
            if(key > val){
                pred = check[i];
            }else{
                if(key < val){
                    succ = check[i];
                    break;
                }
            }
        }
        return {pred,succ};
    }
};