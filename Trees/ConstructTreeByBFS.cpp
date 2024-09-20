//* Conversion of TreeNode array into Tree level order wise *//

// To enter null in array Please type "NULL" at the time of Node Input
#include "TreeNode_Class.cpp"
#include <queue>
//Function to check how your Tree looks in preorder traversal
void displayPre(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<' ';
    displayPre(root->left);
    displayPre(root->right);
}
TreeNode* constructTree(TreeNode* arr[],int n){
    TreeNode* root = arr[0];
    int i=1;
    int j=2;
    queue<TreeNode*>q;
    q.push(root);
    while(q.size() && i<n){
        TreeNode* temp = q.front();
        q.pop();
        TreeNode* l;
        TreeNode* r;
        l = arr[i];
        if(j<n){
            r = arr[j];
        }
        else{
            r = NULL;
        }
        temp->left = l;
        temp->right = r;
        if(l != NULL){
            q.push(l);
        }
        if(r != NULL){
            q.push(r);
        }
        i += 2;
        j += 2;
    }
    return root;
}
int main(){
    cout<<"Welcome to the world of C++ programming"<<endl;
    cout<<"The program is dedicated to convert an array to a Tree\n";
    cout<<"Please enter the number of nodes = ";
    int n;
    cin>>n;
    TreeNode* arr[n];
    for(int i=0;i<n;i++){
        string val;
        cout<<"Please enter the value of "<<i+1<<" node = ";
        cin>>val;
        if(i==0 && n!=0 && val == "NULL"){
            cout<<"If you declare size not equal to zero\n";
            cout<<"Ensure that your first node cannot be null\n";
            cout<<"Program is now terminated , try again\n";
            cout<<"Do not make the same mistake again\n";
            break;
        }
        if(val!="NULL"){
            TreeNode* help = new TreeNode(stoi(val));
            arr[i] = help;
        }
        else{
            arr[i] = NULL;
        }
    }
    cout<<"Your array looks like = {";
    for(int i=0;i<n;i++){
        if(arr[i]!=NULL){
            if(i<n-1){
                cout<<arr[i]->val<<",";
            }
            else{
                cout<<arr[i]->val<<"}";
            }
        }
        else{
            if(i<n-1){
                cout<<"NULL"<<",";
            }
            else{
                cout<<"NULL"<<"}";
            }
        }
    }
    TreeNode* root = constructTree(arr,n);
    cout<<"\nYour Tree in preorder traversal looks like:- ";
    displayPre(root);
    return 0;
}