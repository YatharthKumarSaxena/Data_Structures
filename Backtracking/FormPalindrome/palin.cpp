#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPalindrome(string curr){
        string temp = curr;
        reverse(temp.begin(),temp.end());
        return temp == curr;
    }
    void doBacktrack(int n, int currLen,string curr,vector<string>& ans){
        if(currLen==n){
            if(checkPalindrome(curr)){
                ans.push_back(curr);
            }
            return;
        }
        for(int i=0;i<=9;i++){
            // 4, 2 0123  // 5 ,2 01234
            int check = (n+1)/2;
            if(currLen<check){
                doBacktrack(n,currLen+1,curr+char(48+i),ans);
            }else{
                // 12321
                int idx = currLen-check;
                if(char(48+i)==curr[n - 1 - currLen]){
                    doBacktrack(n,currLen+1,curr+char(48+i),ans);
                }
            }
        }
    }
    vector<string> generatePalindromes(int n) {
        vector<string> ans;
        doBacktrack(n,0,"",ans);
        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> testCases = {1, 2, 3, 4, 5};

    for(int n : testCases){

        vector<string> ans = obj.generatePalindromes(n);

        cout << "n = " << n << "\n";
        cout << "Total Palindromes: " << ans.size() << "\n";

        for(string s : ans){
            cout << s << " ";
        }

        cout << "\n\n";
    }

    return 0;
}