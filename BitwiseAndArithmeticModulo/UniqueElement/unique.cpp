#include <vector>
using namespace std;

class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int ans = arr[0];
        int n = arr.size();
        for(int i=1;i<n;i++){
            ans ^= arr[i];
        }
        return ans;
    }
};