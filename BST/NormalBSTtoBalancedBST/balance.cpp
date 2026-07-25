#include <iostream>
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
    Node* transformIntoBST(int lo,int hi,vector<int>& arr){
        if(lo>hi)return NULL;
        int mid = lo+(hi-lo)/2;
        Node* root = new Node(arr[mid]);
        root->left = transformIntoBST(lo,mid-1,arr);
        root->right = transformIntoBST(mid+1,hi,arr);
        return root;
    }
    void prepareVector(Node* root, vector<int>& v) {
        if (root == NULL)
            return;

        prepareVector(root->left, v);
        v.push_back(root->data);
        prepareVector(root->right, v);
    }
    Node* balanceBST(Node* root) {
        // Code here
        vector<int>help;
        prepareVector(root,help);
        int n = help.size();
        return transformIntoBST(0,n-1,help);
    }
};