#include <iostream>
using namespace std;

// BST Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int minValue(Node* root) {
        while (root) {
            if (root->left == NULL)
                return root->data;

            root = root->left;
        }

        return 0;
    }
};