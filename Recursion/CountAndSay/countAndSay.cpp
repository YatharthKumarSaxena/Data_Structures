#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string curr = countAndSay(n-1);
        string ans = "";
        int freq = 1;
        for(int i=0;i<curr.length()-1;i++){
            char character = curr[i];
            if(character == curr[i+1])freq++;
            else{
                ans += (to_string(freq)+character);
                freq = 1;
            }
        }
        ans += (to_string(freq)+curr[curr.length()-1]);
        return ans;
    }
};