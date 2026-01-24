#include <string>
using namespace std;

class Solution {
  public:
    bool checkPalindrome(string s, int start, int end){
       if(start >= end)return true;
       if(s[start]!=s[end])return false;
       return checkPalindrome(s,start+1,end-1);
    }
    bool isPalindrome(int n) {
        // code here.
        string s = to_string(n);
        return checkPalindrome(s,0,s.length()-1);
    }
};