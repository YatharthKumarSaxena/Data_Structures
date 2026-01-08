#include <cmath>
using namespace std;

class Solution1 {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        return pow(2,n)-1;
    }
};

class Solution2 {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if(n==0)return 0;
        int left = towerOfHanoi(n-1,from,aux,to);
        int move = 1;
        int right = towerOfHanoi(n-1,aux,to,from);
        return move + left + right;
    }
};