#include <iostream>
using namespace std;
// Optimiized Quick Sort
int partition(int arr[],int startingIdx,int endingidx){
    // This Technique is an Example of Randomized Quick Sort
    int pivotEle = arr[(startingIdx+endingidx)/2]; // Avoiding choosing last and first element as pivot 
    int count = 0;
    for(int i=startingIdx;i<=endingidx;i++){
        if(arr[i]==pivotEle)continue;
        else if(arr[i]<pivotEle)count++;
    }
    int pivotIdx = startingIdx+count;
    swap(arr[(startingIdx+endingidx)/2],arr[pivotIdx]);
    int i = startingIdx;
    int j = endingidx;
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
void quickSort(int arr[],int startingIdx,int endingIdx){
    if(startingIdx >= endingIdx)return;
    int pivotIdx = partition(arr,startingIdx,endingIdx);
    quickSort(arr,startingIdx,pivotIdx-1);
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