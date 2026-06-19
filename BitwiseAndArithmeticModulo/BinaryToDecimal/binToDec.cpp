#include <string>
using namespace std;

class Solution {
  public:
    int binaryToDecimal(string& b) {
        // code here
        int ans = 0;
        int base = 1;
        int n = b.length();
        for(int i=n-1;i>=0;i--){
            ans += base*(b[i]-48);
            base *= 2;
        }
        return ans;
    }
};