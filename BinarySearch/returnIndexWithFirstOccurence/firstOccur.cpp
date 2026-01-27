#include <vector>
using namespace std;

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int idx = -1;
        int lo = 0;
        int hi = arr.size()-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]==k){
                idx = mid;
                hi = mid-1;
            }
            else if(arr[mid]>k)hi = mid-1;
            else lo = mid+1;
        }
        return idx;
    }
};

