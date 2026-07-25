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
    bool checkIsSymmetric(Node* r1, Node* r2) {
        if (!r1 && !r2)
            return true;

        if ((!r1 && r2) || (r1 && !r2))
            return false;

        if (r1->data != r2->data)
            return false;

        return checkIsSymmetric(r1->left, r2->right) &&
               checkIsSymmetric(r1->right, r2->left);
    }

    bool isSymmetric(Node* root) {
        if (!root)
            return true;

        return checkIsSymmetric(root->left, root->right);
    }
};