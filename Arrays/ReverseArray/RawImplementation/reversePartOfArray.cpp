#include <iostream>
#include <vector>
using namespace std;

void reverseArray(int start, int end, vector<int> &arr){
    if(start<0 || end >= arr.size())return;
    int i = start;
    int j = end;
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
    int st,end;
    cin>>st>>end;
    reverseArray(st,end,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}