#include <bits/stdc++.h>
using namespace std;

class Solution1 {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());

        int n = arr.size();

        vector<int> dp(n, 1);

        // dp[i] = largest valid subset starting from i
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(arr[j] % arr[i] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // Lexicographically greatest starting element
        int start = 0;
        int maxLen = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                start = i;
            }
        }

        vector<int> ans;
        int current = start;

        ans.push_back(arr[current]);

        while(dp[current] > 1) {

            // Find largest possible next element
            for(int j = n - 1; j > current; j--) {
                if(arr[j] % arr[current] == 0 &&
                   dp[j] == dp[current] - 1) {

                    current = j;
                    ans.push_back(arr[current]);
                    break;
                }
            }
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n,-1);
        vector<int> parent(n, -1);
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }

        vector<int>ans;

        int maxi = 0;
        int last = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] > maxi) {
                maxi = dp[i];
                last = i;
            }
        }

        while(last != -1){
            ans.push_back(nums[last]);
            last = parent[last];
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};