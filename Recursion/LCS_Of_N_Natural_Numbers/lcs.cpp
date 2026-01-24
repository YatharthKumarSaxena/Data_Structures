// C++ program to  print all increasing sequences of
// length 'k' such that the elements in every sequence
// are from first 'n' natural numbers.
#include<iostream>
using namespace std;

// A utility function to print contents of arr[0..k-1]
void printArr(int arr[], int k)
{
    for (int i=0; i<k; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// A recursive function to print all increasing sequences
// of first n natural numbers.  Every sequence should be
// length k. The array arr[] is used to store current
// sequence.
void printSeqUtil(int i,int n, int k, int &len, int arr[])
{
    if(len == k){
        printArr(arr,k);
        return;
    }
    if(i>=n){
        return;
    }
    i = i+1;
    printSeqUtil(i,n,k,len,arr);
    arr[len++] = i;
    printSeqUtil(i,n,k,len,arr);
    len--;
}

// This function prints all increasing sequences of
// first n natural numbers. The length of every sequence
// must be k.  This function mainly uses printSeqUtil()
void printSeq(int n, int k)
{
    int arr[k];  // An array to store individual sequences
    int len = 0; // Initial length of current sequence
    printSeqUtil(0, n, k, len, arr);
}

// Driver program to test above functions
int main()
{
    int k = 3, n = 7;
    printSeq(n, k);
    return 0;
}