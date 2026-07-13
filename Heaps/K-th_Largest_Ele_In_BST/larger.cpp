#include <vector>
#include <queue>
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
    void prepareVector(Node *root,vector<int>& v){
        if(root==NULL)return;
        prepareVector(root->left,v);
        v.push_back(root->data);
        prepareVector(root->right,v);
    }
    int kthLargest(Node *root, int k) {
        // code here
        vector<int>v;
        prepareVector(root,v);
        int n = v.size();
        if(k>n)return -1;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(v[i]);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};