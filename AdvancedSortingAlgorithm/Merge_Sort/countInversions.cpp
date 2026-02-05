#include <vector>
using namespace std;

class Solution {
  public:
    int countInversions(vector<int>& arr,int left,int mid,int right){
       int n1 = mid-left+1;
       int n2 = right-mid;
       vector<int>L(n1);
       vector<int>R(n2);
       for(int i=0;i<n1;i++){
           L[i]=arr[left+i];
       }
       for(int j=0;j<n2;j++){
           R[j]=arr[mid+1+j];
       }
       int i=0;
       int j=0;
       int k = left;
       int count=0;
       while(i<n1 && j<n2){
           if(L[i]>R[j]){
               count += (n1-i);
               arr[k++] = R[j++];
           }else{
               arr[k++] = L[i++];
           }
       }
       while(i<n1){
           arr[k++]=L[i++];
       }
       while(j<n2){
           arr[k++]=R[j++];
       }
       return count;
    }
    int doMergeSort(vector<int>&nums,int left,int right){
        if(left>=right)return 0;
        int mid = left+(right-left)/2;
        int count = 0;
        count += doMergeSort(nums,left,mid);
        count += doMergeSort(nums,mid+1,right);
        count += countInversions(nums,left,mid,right);
        return count;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        return doMergeSort(arr,0,arr.size()-1);
    }
};