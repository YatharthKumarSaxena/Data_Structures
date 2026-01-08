#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    int findMax(vector<int> &arr,int idx){
        if(arr.size()==idx)return INT_MIN;
        return max(arr[idx],findMax(arr,idx+1));
    }
    int largest(vector<int> &arr) {
        return findMax(arr,0);
    }
};
