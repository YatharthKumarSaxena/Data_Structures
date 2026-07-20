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
// Solution 1 : Iterative (Two Stacks)
/////////////////////////////////////////////////////////

class Solution1 {
public:
    vector<int> postOrder(Node* root) {

        vector<int> ans;

        if (root == nullptr)
            return ans;

        stack<Node*> st1, st2;

        st1.push(root);

        while (!st1.empty()) {

            Node* node = st1.top();
            st1.pop();

            st2.push(node);

            if (node->left)
                st1.push(node->left);

            if (node->right)
                st1.push(node->right);
        }

        while (!st2.empty()) {
            ans.push_back(st2.top()->data);
            st2.pop();
        }

        return ans;
    }
};

/////////////////////////////////////////////////////////
// Solution 2 : Recursive
/////////////////////////////////////////////////////////

class Solution2 {
public:
    void doPostOrder(Node* root, vector<int>& ans) {

        if (root == nullptr)
            return;

        doPostOrder(root->left, ans);
        doPostOrder(root->right, ans);
        ans.push_back(root->data);
    }

    vector<int> postOrder(Node* root) {

        vector<int> ans;
        doPostOrder(root, ans);
        return ans;
    }
};