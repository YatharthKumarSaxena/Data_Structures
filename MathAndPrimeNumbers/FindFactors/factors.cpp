#include <vector>
#include <cmath>
using namespace std;

class Solution {
  public:
    vector<int> getDivisors(int n) {
        // code here
        vector<int>ans;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                ans.push_back(i);
            }
        }
        for(int i=sqrt(n);i>=1;i--){
            if(n%i==0){
                if(n/i != i)ans.push_back(n/i);
            }
        }
        return ans;
    }
};