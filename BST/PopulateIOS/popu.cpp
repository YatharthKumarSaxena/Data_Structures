#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution {
  public:
    void prepareInVector(Node* root,vector<Node*>& ans){
        if(!root)return;
        prepareInVector(root->left,ans);
        ans.push_back(root);
        prepareInVector(root->right,ans);
    }

    void populateNext(Node *root) {
        // code here
        vector<Node*>check;
        prepareInVector(root,check);
        int n = check.size();
        Node* pred = NULL;
        Node* succ = NULL;
        for(int i=0;i<n-1;i++){
            check[i]->next = check[i+1];
        }
        check[n-1]->next = NULL;
        return;
    }
};