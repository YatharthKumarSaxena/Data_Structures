#include <climits>
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
    int ans = INT_MIN;
    int findMaxNodeValue(Node* node){
        if(!node)return 0;
        int lSum = findMaxNodeValue(node->left);
        int rSum = findMaxNodeValue(node->right);
        int sum = lSum + rSum + node->data;
        if(ans == INT_MIN)ans = sum;
        else ans = max(ans, sum);
        return sum;
    }
    int maxSubtreeSum(Node* root) {
        // code here
        findMaxNodeValue(root);
        return ans;
    }
};
