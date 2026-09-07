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
    int ans = 0;
    int giveSumNodeValue(Node* node, int target){
        if(!node)return 0;
        int lSum = giveSumNodeValue(node->left,target);
        int rSum = giveSumNodeValue(node->right,target);
        int sum = lSum + rSum + node->data;
        if(sum == target)ans++;
        return sum;
    }

    int countSubtrees(Node* root, int x) {
        // code here
        giveSumNodeValue(root, x);
        return ans;
    }
};