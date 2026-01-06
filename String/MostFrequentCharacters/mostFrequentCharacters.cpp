#include <algorithm>
#include <string>
using namespace std;

class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        sort(s.begin(),s.end());
        int max = 0;
        int count = 1;
        char ans = '\0';
        char currChar = s[0];
        for(int i=1;i<s.length();i++){
            if(s[i]!=currChar){
                if(count>max){
                    ans = currChar;
                    max = count;
                }
                count = 1;
                currChar = s[i];
            }
            else count++;
        }
        if(count>max){
            ans = s[s.length()-1];
        }
        return ans;
    }
};