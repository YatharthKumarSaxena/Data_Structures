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
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        int n = arr.size();
        return transformIntoBST(0,n-1,arr);
    }
};