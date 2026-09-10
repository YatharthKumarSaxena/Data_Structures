#include <cmath>

class Solution {
  public:
    int sumOfSeries(int n) {
        // code here
        return pow((n*(n+1))/2,2);
    }
};