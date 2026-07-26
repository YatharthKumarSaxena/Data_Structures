#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    void prepareInVector(Node* root, vector<int>& ans) {
        if (!root)
            return;

        prepareInVector(root->left, ans);
        ans.push_back(root->data);
        prepareInVector(root->right, ans);
    }

    int getCount(Node* root, int l, int h) {
        vector<int> nodes;
        prepareInVector(root, nodes);

        int count = 0;

        for (int val : nodes) {
            if (l <= val && val <= h)
                count++;
        }

        return count;
    }
};