#include <vector>
using namespace std;

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int lo = 0;
        int hi = arr.size()-1;
        if(target>arr[hi])return hi+1;
        int idx = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]>=target){
                idx = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return idx;
    }
};
