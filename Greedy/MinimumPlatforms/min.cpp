#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dept) {
        sort(arr.begin(), arr.end());
        sort(dept.begin(), dept.end());

        int i = 0;
        int j = 0;
        int n = arr.size();

        int maxPlatforms = 0;
        int currPlatforms = 0;

        while (i < n && j < n) {
            if (arr[i] <= dept[j]) {
                i++;
                currPlatforms++;
                maxPlatforms = max(maxPlatforms, currPlatforms);
            } else {
                currPlatforms--;
                j++;
            }
        }

        return maxPlatforms;
    }
};