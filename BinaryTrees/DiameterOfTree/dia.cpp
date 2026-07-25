#include <bits/stdc++.h>
using namespace std;

// Definition for Node
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
    int findMaxDia(Node* root) {
        if (!root) return 0;

        return 1 + max(findMaxDia(root->left), findMaxDia(root->right));
    }

    int diameter(Node* root) {
        if (!root) return 0;

        int dia = findMaxDia(root->left) + findMaxDia(root->right);

        return max(dia,
                   max(diameter(root->left),
                       diameter(root->right)));
    }
};

int main() {
    // Create tree:
    //      1
    //     / \
    //    2   3

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Solution obj;
    cout << "Diameter (in edges): " << obj.diameter(root) << endl;

    return 0;
}