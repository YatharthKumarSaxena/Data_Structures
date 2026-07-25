#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    void levelOrderTraversal(Node* root, int level, vector<int>& ans) {
        if (!root) return;

        if (level == ans.size())
            ans.push_back(root->data);
        else
            ans[level] = root->data;

        levelOrderTraversal(root->left, level + 1, ans);
        levelOrderTraversal(root->right, level + 1, ans);
    }

    vector<int> rightView(Node* root) {
        vector<int> ans;
        levelOrderTraversal(root, 0, ans);
        return ans;
    }
};