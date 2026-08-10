#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> commonElements(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> mp;
        vector<int> ans;

        // Frequency of elements in a
        for (int x : a) {
            mp[x]++;
        }

        // Check elements of b
        for (int x : b) {
            if (mp[x] > 0) {
                ans.push_back(x);
                mp[x]--;
            }
        }

        // Sorted order
        sort(ans.begin(), ans.end());

        return ans;
    }
};