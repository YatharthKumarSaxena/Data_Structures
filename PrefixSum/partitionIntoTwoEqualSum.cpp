#include <vector>
using namespace std;

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i=1;i<n;i++){
            arr[i] += arr[i-1];
        }
        for(int i=0;i<n;i++){
            if(2*arr[i] == arr[n-1])return true;
        }
        return false;
    }
};
