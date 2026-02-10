#include <vector>
using namespace std;

class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low>=high)return;
        int pIdx = partition(arr,low,high);
        quickSort(arr,low,pIdx-1);
        quickSort(arr,pIdx+1,high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivotEle = arr[low];
        int pIdx = low;
        for(int i=low+1;i<=high;i++){
            if(pivotEle>arr[i])pIdx++;
        }
        swap(arr[pIdx],arr[low]);
        int i = low;
        int j = high;
        while(i < pIdx && j > pIdx){
            if(arr[i] < pivotEle){
                i++;
            }
            else if(arr[j] >= pivotEle){
                j--;
            }
            else{
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        return pIdx;
    }
};