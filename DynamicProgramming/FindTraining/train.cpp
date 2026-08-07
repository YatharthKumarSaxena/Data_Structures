#include <vector>
using namespace std;

class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
        vector<bool> dp(n + 1, false);
        for(int i = 1; i <= n; i++){
            bool a = (i-1 >= 0) ? dp[i-1] : true;
            bool b = (i-x >= 0) ? dp[i-x] : true;
            bool c = (i-y >= 0) ? dp[i-y] : true;
        
            dp[i] = !(a && b && c);
        }
        return dp[n];
    }
};
