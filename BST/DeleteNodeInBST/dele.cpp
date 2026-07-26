#include <iostream>

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

class Solution {
  public:
    int findIos(Node* root){
        Node* temp = root;
        if(!temp)return -1;
        if(!temp->right) return -1;
        else temp = temp->right;
        int ios = temp->data;
        while(temp->left){
            temp = temp->left;
            ios = temp->data;
        }
        return ios;
    }
    Node* delNode(Node* root, int x) {
        // code here
        if(!root)return NULL;
        else if(root->data == x){
            if(!root->left && !root->right)return NULL;
            else if(!root->left || !root->right){
                if(!root->left){
                    return root->right;
                }else{
                    return root->left;
                }
            }
            else{
                int iosVal = findIos(root);
                root->data = iosVal;
                root->right = delNode(root->right,iosVal);
                return root;
            }
        }
        else if(root->data < x)root->right = delNode(root->right,x);
        else root->left = delNode(root->left,x);
        return root;
    }
};