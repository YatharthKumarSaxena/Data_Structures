#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node Class
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

/////////////////////////////////////////////////////////
// Recursive Preorder
/////////////////////////////////////////////////////////

class Solution1 {
public:
    void doPreOrder(Node* root, vector<int>& ans) {
        if (root == nullptr)
            return;

        ans.push_back(root->data);
        doPreOrder(root->left, ans);
        doPreOrder(root->right, ans);
    }

    vector<int> preOrder(Node* root) {
        vector<int> ans;
        doPreOrder(root, ans);
        return ans;
    }
};

/////////////////////////////////////////////////////////
// Iterative Preorder
/////////////////////////////////////////////////////////

class Solution2 {
public:
    vector<int> preOrder(Node* root) {

        vector<int> ans;

        if (root == nullptr)
            return ans;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {

            Node* node = st.top();
            st.pop();

            ans.push_back(node->data);

            if (node->right)
                st.push(node->right);

            if (node->left)
                st.push(node->left);
        }

        return ans;
    }
};