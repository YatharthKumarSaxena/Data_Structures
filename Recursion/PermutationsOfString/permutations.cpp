#include <vector>
#include <string>
#include <set>
using namespace std;

// Medium Solution but still complex due to substr as it has O(n) T.C alone
class Solution1 {
  public:
    void findPermutations(set<string>& ans, string helper, string s){
        if(s.length()<=1){
            string final = helper+s;
            ans.insert(final);
            return;
        }
        for(int i=0;i<s.length();i++){
            helper += s[i];
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            findPermutations(ans,helper,left+right);
            helper.pop_back();
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        if(s.length()==0)return {};
        if(s.length()==1)return {s};
        set<string> ans;
        findPermutations(ans,"",s);
        return vector<string>(ans.begin(), ans.end());

    }
};

// Worst Solution
class Solution2 {
  public:
    void findPermutations(vector<string>& ans, string helper, string s){
        if(s.length()<=1){
            string final = helper+s;
            for(int i=0;i<ans.size();i++){
                if(ans[i]==final)return;
            }
            ans.push_back(final);
            return;
        }
        for(int i=0;i<s.length();i++){
            helper += s[i];
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            findPermutations(ans,helper,left+right);
            helper.pop_back();
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        if(s.length()==0)return {};
        if(s.length()==1)return {s};
        vector<string> ans;
        findPermutations(ans,"",s);
        return ans;
    }
};

// Most Optimized
class Solution3 {
public:
    void findPermutations(vector<string>& ans, string& s, int start) {
        if (start == s.length() - 1) {
            ans.push_back(s);
            return;
        }
        
        bool used[128] = {false};  // ASCII characters ke liye
        
        for (int i = start; i < s.length(); i++) {
            if (used[s[i]]) continue;  // Direct array access - fastest!
            used[s[i]] = true;
            
            swap(s[start], s[i]);
            findPermutations(ans, s, start + 1);
            swap(s[start], s[i]);
        }
    }
    
    vector<string> findPermutation(string &s) {
        if (s.empty()) return {};
        vector<string> ans;
        findPermutations(ans, s, 0);
        return ans;
    }
};

// Most Optimized in terms of Time and Space
class Solution {
public:
    void findPermutations(vector<string>& ans, string& s, int start) {
        if (start == s.length() - 1) {
            ans.push_back(s);
            return;
        }
        
        bool used[26] = {false};  // ASCII characters ke liye
        
        for (int i = start; i < s.length(); i++) {
            if (used[s[i]-65]) continue;  // Direct array access - fastest!
            used[s[i]-65] = true;
            
            swap(s[start], s[i]);
            findPermutations(ans, s, start + 1);
            swap(s[start], s[i]);
        }
    }
    
    vector<string> findPermutation(string &s) {
        if (s.empty()) return {};
        vector<string> ans;
        findPermutations(ans, s, 0);
        return ans;
    }
};