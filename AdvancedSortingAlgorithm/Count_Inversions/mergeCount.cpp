#include <iostream>
#include <vector>
using namespace std;

// Declaring A Global Variable
int mergeCount(vector<int>& v1,vector<int>& v2){
    int c = 0;
    // Initialising Pointers
    int i = 0; // For v1
    int j = 0; // For v2
    while(i<v1.size() && j<v2.size()){
        if(v1[i]>v2[j]){
            c += (v1.size()-i);
            j++;
        }
        else{
            i++;
        }
    }
    return c;
}

void merge(vector<int>& ans,vector<int>& v1,vector<int>& v2){
    int size1 = v1.size();
    int size2 = v2.size();
    // Initializing Pointers
    int i=0,j=0,k=0;
    while(i<size1 && j<size2){
        if(v1[i]<=v2[j])ans[k++]=v1[i++];
        else ans[k++]=v2[j++];
    }
    for(int t=i;t<size1;t++)ans[k++]=v1[t];
    for(int t=j;t<size2;t++)ans[k++]=v2[t];
    return;
}

int mergeSort(vector<int>& v){
    int c = 0;
    int n = v.size();
    if(n==1)return 0;
    int n1 = n/2;
    int n2 = n-n1;
    vector<int>v1(n1,0);
    vector<int>v2(n2,0);
    for(int i=0;i<n1;i++){
        v1[i] = v[i];
    }
    for(int i=0;i<n2;i++){
        v2[i] = v[n1+i];
    }
    c += mergeSort(v1);
    c += mergeSort(v2);
    // Count the Inversions
    c += mergeCount(v1,v2);
    // Merge the Sorted Vectors/Arrays
    merge(v,v1,v2);
    v1.clear();
    v2.clear();
    return c;
}

int main(){
    cout<<"\nWelcome to the World of Programming\n";
    cout<<"Solving the Problem of Inversion Count using Merge Count\n";
    int arr[] = {5,1,3,0,4,9,6};
    int n = sizeof(arr)/sizeof(int);
    // Copy the Array into Vector
    vector<int> v(arr,arr+n);
    int ans = mergeSort(v);
    cout<<"Inversion Count is "<<ans<<endl<<endl;
    return 0;
}