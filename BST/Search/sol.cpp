#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        while(root){
            if(root->data==key)return true;
            else if(root->data > key)root = root->left;
            else root = root->right;
        }
        return false;
    }
};