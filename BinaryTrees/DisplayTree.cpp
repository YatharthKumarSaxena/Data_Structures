#include "TreeNode_Class.cpp"
#include <stack>

/* Note:- Please run these codes in demoTree.cpp 
in that file a demo Tree is available */


// Recursive Approach 

//PreOrder Traversal
void displayPre(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<' ';
    displayPre(root->left);
    displayPre(root->right);
}

//InOrder Traversal
void displayIn(TreeNode* root){
    if(root==NULL){
        return;
    }
    displayIn(root->left);
    cout<<root->val<<' ';
    displayIn(root->right);
}

//PostOrder TraversaL
void displayPost(TreeNode* root){
    if(root==NULL){
        return;
    }
    displayPost(root->left);
    displayPost(root->right);
    cout<<root->val<<' ';
}

// Iterative Approach

// PreOrder Traversal
void displayPreIt(TreeNode* root){
    if(root == NULL){
        cout<<"Your Tree is empty\n";
        return;
    }
    stack<TreeNode*>st;
    st.push(root);
    while(st.size()>0){
        TreeNode* temp = st.top();
        st.pop();
        cout<<temp->val<<' ';
        if(temp->right)st.push(temp->right);
        if(temp->left)st.push(temp->left);
    }
}

// PostOrder Traversal
void displayPostIt(TreeNode* root){
    if(root == NULL){
        cout<<"Your Tree is empty\n";
        return;
    }
    stack<TreeNode*>st;
    stack<TreeNode*>helper;
    st.push(root);
    while(st.size()>0){
        TreeNode* temp = st.top();
        st.pop();
        helper.push(temp);
        if(temp->left)st.push(temp->left);
        if(temp->right)st.push(temp->right);
    }
    while(helper.size()>0){
        TreeNode* temp = helper.top();
        helper.pop();
        cout<<temp->val<<' ';
    }
}

// InOrder Traversal
void displayInIt(TreeNode* root){
    if(root == NULL){
        cout<<"Your Tree is empty\n";
        return;
    }
    TreeNode* Node = root;
    stack<TreeNode*>st;
    while(st.size()>0 || Node!=NULL){
        if(Node != NULL){
            st.push(Node);
            Node = Node->left;
        }
        else{
            TreeNode* temp = st.top();
            st.pop();
            cout<<temp->val<<' ';
            Node = temp->right; 
        }
    }
}