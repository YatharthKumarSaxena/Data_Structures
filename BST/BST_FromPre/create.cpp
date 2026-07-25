#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
    Node* buildPreAndIn(vector<int>& preorder,int preLo,int preHi, vector<int>& inorder,int inLo,int inHi){
        if(preLo>preHi)return NULL;
        Node* root = new Node(preorder[preLo]);
        int in = inLo;
        int leftDis = 0;
        while(inorder[in]!=preorder[preLo]){
            in++;
        }
        leftDis = in - inLo;
        root->left = buildPreAndIn(preorder,preLo+1,preLo+leftDis,inorder,inLo,in-1+leftDis-1);
        root->right = buildPreAndIn(preorder,preLo+leftDis+1,preHi,inorder,in+1,inHi);
        return root;
    }
    Node* preToBST(vector<int>& pre) {
        // code here
        int n = pre.size();
        if(n==0)return NULL;
        vector<int>in(pre);
        sort(in.begin(),in.end());
        int n1 = pre.size();
        int n2 = in.size();
        return buildPreAndIn(pre,0,n1-1,in,0,n2-1);
    }
};