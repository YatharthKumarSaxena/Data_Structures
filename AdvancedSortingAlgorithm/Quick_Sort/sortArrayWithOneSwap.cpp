// C++ program to sort using one swap
#include<iostream>
#include<algorithm>
using namespace std;

// This function sorts an array that can be sorted
// by single swap
void sortByOneSwap(int arr[], int n)
{
    if(n <= 1)return;
    int leftIdx = 0;
    int rightIdx = n-1;
    // Find Left Idx
    // Find Mountain Peak
    if(arr[leftIdx]<arr[leftIdx+1]){
        while(leftIdx < n-1 && arr[leftIdx]<arr[leftIdx+1])leftIdx++;
    }
    // Find Right Idx
    // Find Mountain Valley
    if(arr[rightIdx]>arr[rightIdx-1]){
        while(rightIdx > 0 && arr[rightIdx]>arr[rightIdx-1])rightIdx--;
    }
    if(leftIdx>=rightIdx)return;
    int temp = arr[leftIdx];
    arr[leftIdx] = arr[rightIdx];
    arr[rightIdx] = temp;
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Driver program to test insertion sort */
int main()
{
    int arr[] = {10, 30, 20, 40, 50, 60, 70};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, n);

    sortByOneSwap(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);

    return 0;
}