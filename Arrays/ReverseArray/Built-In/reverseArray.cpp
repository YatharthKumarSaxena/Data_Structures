#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        reverse(arr.begin(),arr.end());
    }
};