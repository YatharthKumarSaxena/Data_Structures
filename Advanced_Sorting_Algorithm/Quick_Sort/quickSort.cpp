#include <iostream>
using namespace std;

int partition(int arr[],int startIdx,int endingIdx){
    int pivotEle = arr[startIdx];
    int count = 0;
    for(int i=startIdx+1;i<=endingIdx;i++){
        if(arr[i]<=pivotEle)count++;
    }
    int pivotIdx = startIdx+count;
    swap(arr[startIdx],arr[pivotIdx]);
    int i = startIdx;
    int j = endingIdx;
    while(i<pivotIdx && j>pivotIdx){
        if(arr[i]<=pivotEle)i++;
        else if(arr[j]>pivotEle)j--;
        else if(arr[i]>pivotEle && arr[j]<pivotEle){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}
void quickSort(int arr[],int startIdx,int endingIdx){
    if(startIdx >= endingIdx)return;
    int pivotIdx = partition(arr,startIdx,endingIdx);
    quickSort(arr,startIdx,pivotIdx-1);
    quickSort(arr,pivotIdx+1,endingIdx);
}

int main(){
    cout<<"\nWelcome to the World of Programming\n";
    int arr[] = {2,43,12,78,45,78,34,21,1,-5};
    int n = sizeof(arr)/sizeof(int);
    cout<<"Your Array looks as given below :-\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr,0,n-1);
    cout<<"After Quick Sort Array looks as given below:-\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}