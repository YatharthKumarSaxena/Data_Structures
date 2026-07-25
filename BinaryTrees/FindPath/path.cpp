#include <vector>
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
    void findPath(Node* root,vector<int>helper,vector<vector<int>>& ans){
        if(!root)return;
        if(!root->left && !root->right){
            helper.push_back(root->data);
            ans.push_back(helper);
            return;
        }
        helper.push_back(root->data);
        findPath(root->left,helper,ans);
        findPath(root->right,helper,ans);
    }
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        findPath(root,{},ans);
        return ans;
    }
};