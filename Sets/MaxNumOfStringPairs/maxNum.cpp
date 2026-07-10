#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string>st;
        int n = words.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            string checkStr = words[i];
            reverse(checkStr.begin(),checkStr.end());
            if(checkStr!=words[i]){
                if(st.find(checkStr)==st.end())st.insert(words[i]);
                else ans++;
            }
        }
        return ans;
    }
};