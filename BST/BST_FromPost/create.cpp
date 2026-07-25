#include <iostream>
#include <algorithm>
#include <vector>
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
    Node* buildPostAndIn(vector<int>& postorder,int postLo,int postHi, vector<int>& inorder,int inLo,int inHi){
        if(postLo>postHi)return NULL;
        Node* root = new Node(postorder[postHi]);
        int in = inLo;
        int leftDis = 0;
        while(inorder[in]!=postorder[postHi]){
            in++;
        }
        leftDis = in - inLo;
        root->left = buildPostAndIn(postorder,postLo,postLo+leftDis-1,inorder,inLo,in-1+leftDis-1);
        root->right = buildPostAndIn(postorder,postLo+leftDis,postHi-1,inorder,in+1,inHi);
        return root;
    }
    Node* constructTree(vector<int>& post) {
        // code here
        int n = post.size();
        if(n==0)return NULL;
        vector<int>in(post);
        sort(in.begin(),in.end());
        int n1 = post.size();
        int n2 = in.size();
        return buildPostAndIn(post,0,n1-1,in,0,n2-1);
    }
};