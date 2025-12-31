#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr){
    int i = 0;
    int j = arr.size()-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    reverseArray(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}