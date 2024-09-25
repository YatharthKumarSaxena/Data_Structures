#include "makeYourBST.cpp"
int main(){
    int n;
    cout<<"Welcome to the world of programming\n";
    cout<<"To make your own Binary Search Tree \n";
    cout<<"Please enter the number of nodes of your BST = ";
    cin>>n;
    if(n<=0){
        cout<<"Please enter a natural number !!";
        cout<<endl;
        cout<<"Rerun the program\n";
        return 0;
    }
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Please enter the value of "<<i+1<<" Node = ";
        cin>>arr[i];
    }
    TreeNode* root = makeBST(arr,n);
    // Checking whether BST is formed properly or not
    // For this we are using inorder Traversal
    // Inorder Traversal of BST is always sorted in increasing order
    displayIn(root);
}
