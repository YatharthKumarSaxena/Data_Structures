#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    int findMax(vector<int> &arr,int idx){
        if(arr.size()==idx)return INT_MIN;
        return max(arr[idx],findMax(arr,idx+1));
    }
    int findMin(vector<int> &arr,int idx){
        if(arr.size()==idx)return INT_MAX;
        return min(arr[idx],findMin(arr,idx+1));
    }
    vector<int> getMinMax(vector<int> &arr) {
        // code here()
        vector<int>ans(2,0);
        ans[0] = findMin(arr,0);
        ans[1] = findMax(arr,0);
        return ans;
    }
};
