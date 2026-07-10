#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    void relativeSort(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;

        int n2 = arr2.size();
        for (int i = 0; i < n2; i++) {
            mp[arr2[i]] = mp[arr2[i]];
        }

        int n1 = arr1.size();
        for (int i = 0; i < n1; i++) {
            mp[arr1[i]]++;
        }

        vector<int> ans;
        vector<int> remEle;

        for (int i = 0; i < n2; i++) {
            if (mp.find(arr2[i]) != mp.end()) {
                remEle.insert(remEle.end(), mp[arr2[i]], arr2[i]);
                mp.erase(arr2[i]);
            }
        }

        vector<pair<int, int>> temp(mp.begin(), mp.end());
        sort(temp.begin(), temp.end());

        for (auto &ele : temp) {
            remEle.insert(remEle.end(), ele.second, ele.first);
        }

        ans.insert(ans.end(), remEle.begin(), remEle.end());

        arr1 = ans;
    }
};