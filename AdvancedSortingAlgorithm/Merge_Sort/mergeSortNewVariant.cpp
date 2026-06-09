#include <vector>
using namespace std;

class Solution {
  public:
    int countInversions(vector<int> &arr,int l,int r){
        int crossInversions = 0;
        int mid = l+(r-l)/2;
        int i = mid;
        int j = r;
        int n = r-l+1;
        int k = n-1;
        vector<int>temp(n);
        while(i>=l && j>=mid+1){
            if(arr[i]>arr[j]){
                crossInversions += (j-mid);
                temp[k--] = arr[i--];
            }
            else{
                temp[k--] = arr[j--];
            }
        }
        if(k>=0){
            while(i>=l){
                temp[k--] = arr[i--];
            }
            while(j>=mid+1){
                temp[k--] = arr[j--];
            }
        }
        for(int k=0;k<n;k++){
            arr[k+l] = temp[k];
        }
        return crossInversions;
    }
    int doMergeSort(vector<int> &arr,int l,int r){
        if(l>=r)return 0;
        int mid = l+(r-l)/2;
        int leftInversions = doMergeSort(arr,l,mid);
        int rightInversions = doMergeSort(arr,mid+1,r);
        int crossInversions = countInversions(arr,l,r);
        int totalInversions = leftInversions+rightInversions+crossInversions;
        return totalInversions;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int ans = doMergeSort(arr,0,n-1);
        return ans;
    }
};