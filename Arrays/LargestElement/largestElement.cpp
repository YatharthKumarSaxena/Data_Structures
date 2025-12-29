#include <vector>
using namespace std;

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        if(arr.size()==1)return arr[0];
        int max = arr[0];
        for(int i=1;i<arr.size();i++){
            if(max<arr[i])max = arr[i];
        }
        return max;
    }
};
