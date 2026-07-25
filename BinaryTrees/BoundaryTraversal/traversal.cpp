#include <vector>
using namespace std;


class Node {
  public:
    int data;
    Node* left, *right;
    Node(int data) {
        data = data;
        left = right = nullptr;
    }
}; 

class Solution {
  public:
    vector<int> leftBoundary(Node* root){
        if(!root)return {};
        if(root->left == NULL)return {root->data};
        vector<int>leftB;
        Node* temp = root;
        while(temp->left!=NULL || temp->right!=NULL){
            leftB.push_back(temp->data);
            if(temp->left) temp = temp->left;
            else temp = temp->right;
        }
        return leftB;
    }
    vector<int> rightBoundary(Node* root){
        if(!root)return {};
        vector<int>rightB;
        Node* temp = root;
        while(temp->left!=NULL || temp->right!=NULL){
            rightB.push_back(temp->data);
            if(temp->right) temp = temp->right;
            else temp = temp->left;
             
        }
        return rightB;
    }
    void leafNodes(Node* root,vector<int>& leaves){
        if(!root)return;
        if(root->left == NULL && root->right == NULL){
            leaves.push_back(root->data);
            return;
        }
        leafNodes(root->left,leaves);
        leafNodes(root->right,leaves);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(!root)return {};
        if(root->left == NULL && root->right == NULL)return {root->data};
        vector<int>leftB = leftBoundary(root);
        vector<int>rightB = rightBoundary(root->right);
        vector<int>leaves;
        leafNodes(root,leaves);
        int leftBSize = leftB.size();
        int rightBSize = rightB.size();
        int leavesSize = leaves.size();
        vector<int>boundary;
        for(int i=0;i<leftBSize;i++){
            boundary.push_back(leftB[i]);
        }
        for(int i=0;i<leavesSize;i++){
            boundary.push_back(leaves[i]);
        }
        for(int i=0;i<rightBSize;i++){
            boundary.push_back(rightB[rightBSize-i-1]);
        }
        return boundary;
    }
};