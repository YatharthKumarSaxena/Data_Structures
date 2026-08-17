#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void doBackTrack(int idx, string helper, vector<string>& ans) {
        int n = helper.size();

        if(idx == n) {
            ans.push_back(helper);
            return;
        }

        // Keep current character as it is
        doBackTrack(idx + 1, helper, ans);

        // If character is alphabet
        if(!(helper[idx] >= '0' && helper[idx] <= '9')) {

            // Lowercase -> Uppercase
            if(helper[idx] >= 'a') {
                helper[idx] -= 32;

                doBackTrack(idx + 1, helper, ans);

                helper[idx] += 32;
            }
            // Uppercase -> Lowercase
            else {
                helper[idx] += 32;

                doBackTrack(idx + 1, helper, ans);

                helper[idx] -= 32;
            }
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;

        doBackTrack(0, s, ans);

        return ans;
    }
};