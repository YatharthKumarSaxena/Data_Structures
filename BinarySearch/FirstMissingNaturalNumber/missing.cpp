#include <vector>
using namespace std;

class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // Code here
        int lo = 0;
        int hi = arr.size()-1;
        int idx = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int number = mid+1;
            if(arr[mid]!=number){
                idx = number;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        if(idx == -1)return arr.size()+1;
        return idx;
    }
};