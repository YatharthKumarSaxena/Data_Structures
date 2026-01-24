#include <vector>
#include <string>
using namespace std;

// Worst Solution
class Solution1 {
  public:
    void doRecursion(int n, string helper, vector<string> &ans){
        if(helper.length()==n){
            ans.push_back(helper);
            return;
        }
        doRecursion(n,helper+'0',ans);
        if(!helper.size() || helper[helper.size()-1]!='1')doRecursion(n,helper+'1',ans);
    }
    // #define ll long long
    int countStrings(int n) {
        // code here
        vector<string>ans;
        doRecursion(n,"",ans);
        return ans.size();
    }
};

// Best Solution
class Solution {
public:
    int countStrings(int n) {
        if (n == 1) return 2;

        long long a = 2, b = 3, c;

        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
