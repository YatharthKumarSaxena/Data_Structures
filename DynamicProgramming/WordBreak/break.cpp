#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    unordered_map<string,bool> dp;
    bool solve(string s, vector<string>& wordDict) {
        if(dp.count(s))return dp[s];

        if(s.empty())
            return true;

        for(string word : wordDict) {

            // Check whether word matches at the beginning
            if(s.substr(0, word.size()) == word) {

                // Remove matched word and solve remaining string
                string remaining = s.substr(word.size());

                if(solve(remaining, wordDict))
                    return dp[s] = true;
            }
        }

        return dp[s] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, wordDict);
    }
};

class Solution2 {
public:
    vector<int> dp;

    bool doDP(int i, string& s, unordered_set<string>& dict,
              vector<int>& lengths) {

        if(i == s.size())
            return true;

        if(dp[i] != -1)
            return dp[i];

        for(int len : lengths) {

            if(i + len > s.size())
                continue;

            string word = s.substr(i, len);

            if(dict.count(word)) {
                if(doDP(i + len, s, dict, lengths))
                    return dp[i] = 1;
            }
        }

        return dp[i] = 0;
    }

    bool wordBreak(string &s, vector<string> &dictionary) {

        unordered_set<string> dict;
        unordered_set<int> lengthSet;

        for(string& word : dictionary) {
            dict.insert(word);
            lengthSet.insert(word.size());
        }

        vector<int> lengths(lengthSet.begin(), lengthSet.end());

        dp.assign(s.size(), -1);

        return doDP(0, s, dict, lengths);
    }
};