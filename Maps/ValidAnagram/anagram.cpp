#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 != n2)return false;
        unordered_map<char,int>mp;
        for(int i=0;i<n1;i++){
            mp[s1[i]]++;
        }
        for(int i=0;i<n2;i++){
            char val = s2[i];
            if(mp.find(val)!=mp.end()){
                mp[val]--;
                if(mp[val]==0)mp.erase(val);
            } else return false;
        }
        return true;
    }
};