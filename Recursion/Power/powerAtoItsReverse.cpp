#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int reverseExponentiation(int n) {
        // code here
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int power = stoi(s);
        return pow(n,power);
    }
};