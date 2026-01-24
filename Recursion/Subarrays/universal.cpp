#include <vector>
using namespace std;

class Solution {
public:
    void extend(int start, int end, vector<int>& arr,
                vector<vector<int>>& ans) {
        if (end == arr.size()) return;

        vector<int> temp(arr.begin() + start, arr.begin() + end + 1);
        ans.push_back(temp);

        extend(start, end + 1, arr, ans);
    }

    vector<vector<int>> getSubArrays(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();

        for (int start = 0; start < n; start++) {
            extend(start, start, arr, ans);
        }

        return ans;
    }
};
