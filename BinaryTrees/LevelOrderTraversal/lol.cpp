#include <queue>
#include <vector>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        queue<Node*>qu;
        vector<int>ans;
        qu.push(root);
        while(!qu.empty()){
            Node* node = qu.front();
            ans.push_back(node->data);
            if(node->left)qu.push(node->left);
            if(node->right)qu.push(node->right);
            qu.pop();
        }
        return ans;
    }
};