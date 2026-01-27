#include <vector>
using namespace std;

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // code here
        int lo = 0;
        int hi = arr.size()-1;
        if (hi==0)return 0;
        if(arr[0]>arr[1])return 0;
        if(arr[hi-1]<arr[hi])return hi;
        int ans = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(mid > 0 && mid<arr.size()-1 && arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(mid<arr.size()-1 && arr[mid]<arr[mid+1])lo = mid+1;
            else hi = mid-1;
        }
        return ans;
    }
};