#include <vector>
using namespace std;

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            bool isSwapped = false;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    isSwapped = true;
                    swap(arr[j],arr[j+1]);
                }
            }
            if(!isSwapped)break;
        }
    }
};