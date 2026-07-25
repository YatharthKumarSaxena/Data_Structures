#include <iostream>

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int key) {
        Node* newNode = new Node(key);

        if (!root)
            return newNode;

        Node* temp = root;

        while (temp) {
            if (temp->left == NULL && temp->data > key) {
                temp->left = newNode;
                break;
            }
            else if (temp->right == NULL && temp->data < key) {
                temp->right = newNode;
                break;
            }
            else if (temp->data < key) {
                temp = temp->right;
            }
            else {
                temp = temp->left;
            }
        }

        return root;
    }
};