#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int> qu;
        int n = arr.size();

        // Store indices of all negative elements
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0)
                qu.push(i);
        }

        vector<int> ans(n - k + 1, 0);

        for (int i = 0; i <= n - k; i++) {
            int winSize = i + k;

            while (!qu.empty()) {
                int idx = qu.front();

                if (idx < winSize && idx >= i) {
                    ans[i] = arr[idx];
                    break;
                } else {
                    if (idx < i)
                        qu.pop();
                    else
                        break;
                }
            }
        }

        return ans;
    }
};