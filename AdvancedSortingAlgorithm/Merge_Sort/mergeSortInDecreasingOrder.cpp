#include <iostream> 
#include <vector>
using namespace std;

void merge(vector<int>& ans,vector<int>& v1,vector<int>& v2){
    int size1 = v1.size();
    int size2 = v2.size();
    // Initialises Ponters
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<size1 && j<size2){
        if(v1[i] >= v2[j])ans[k++] = v1[i++]; // '>=' Brings Stability In Merge Sort
        else ans[k++] = v2[j++];
    }
    for(int t=i;t<size1;t++)ans[k++] = v1[t];
    for(int t=j;t<size2;t++)ans[k++] = v2[t];
    return;
}
void mergeSort(vector<int>& v){
    int n = v.size();
    if(n==1)return;
    int n1 = n/2;
    int n2 = n-n1;
    vector<int>v1(n1,0);
    vector<int>v2(n2,0);
    for(int i=0;i<n1;i++){
        v1[i] = v[i];
    }
    for(int i=0;i<n2;i++){
        v2[i] = v[i+n1];
    }
    // Magic Of Recursion in Sort
    mergeSort(v1);
    mergeSort(v2);
    // Merging the Sorted Arrays or Vectors
    merge(v,v1,v2);
    // Deleting the Vectors to Bring Space Complexity from O(nlogn) to O(n)
    v1.clear(); // Clear Deletes the Vector
    v2.clear();
}

int main(){
    cout<<"\nWelcome to the world of programming\n";
    int arr[] = {3,5,1,6,2,3,1,0,2,2,4,5,9,8,7,23,12,34};
    int n = sizeof(arr)/sizeof(int);
    // Copy the array into Vector In C++
    vector<int> v(arr,arr+n);
    cout<<"Before Sorting Vector looks as given below:-\n";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergeSort(v);
    cout<<"Sorted Vector looks as given below:-\n";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
    return 0;
}