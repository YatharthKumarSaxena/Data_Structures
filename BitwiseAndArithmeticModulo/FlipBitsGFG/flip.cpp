#include <vector>
#include <string>
#include <cmath>
using namespace std;

// User function Template for C++

class Solution {
  public:
    vector<string> flipBits(long int N) {
        // code here
        long mask = pow(2,32)-1;
        long val = N^mask;
        vector<string>ans(2);
        ans[0]=to_string(val);
        while(val){
            int rem = val%2;
            ans[1] += string(1,rem+'0');
            val /= 2;
        }
        int n = ans[1].size();
        int noOfZeros = 32-n;
        for(int i=0;i<noOfZeros;i++){
            ans[1] = '0'+ans[1];
        }
        return ans;
    }
};