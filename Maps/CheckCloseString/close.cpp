#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        if(n1 != n2)return false;
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<n1;i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }

        if (mp1.size() != mp2.size())
            return false;

        for (auto &p : mp1) {
            if (mp2.find(p.first) == mp2.end())
                return false;
        }
        
        vector<int> f1, f2;

        for (auto p : mp1)
            f1.push_back(p.second);

        for (auto p : mp2)
            f2.push_back(p.second);

        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        return f1 == f2;
    }
};