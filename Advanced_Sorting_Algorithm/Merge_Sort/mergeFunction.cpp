#include <iostream>
using namespace std;

void merge(int arr[],int size1,int arr1[],int size2,int arr2[]){
    // Initialises Pointer
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < size1 && j < size2){
        if(arr1[i] < arr2[j])arr[k++] = arr1[i++];
        else arr[k++] = arr2[j++];
    }
    if(i < size1){
        for(int t=i;t<size1;t++)arr[k++] = arr1[t];
    }
    if(j < size2){
        for(int t=j;t<size2;t++)arr[k++] = arr1[t];
    }
}

int main(){
    int arr1[] = {1,3,5,7,9};
    int size1 = sizeof(arr1)/sizeof(int);
    int arr2[] = {0,2,4,6,8};
    int size2 = sizeof(arr2)/sizeof(int);
    int n = size1 + size2;
    int arr[n];
    merge(arr,size1,arr1,size2,arr2);
    for(int ele : arr){
        cout<<ele<<" ";
    }
    return 0;
}