#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>prefMin(n,INT_MAX);
        prefMin[0] = prices[0];
        for(int i=1;i<n;i++){
            prefMin[i] = min(prices[i],prefMin[i-1]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,prices[i]-prefMin[i]);
        }
        return ans;
    }
};