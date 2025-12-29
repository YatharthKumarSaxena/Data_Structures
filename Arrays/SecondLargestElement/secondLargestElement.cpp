#include <vector>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int length = arr.size();
        if(length == 1)return -1;
        int max = arr[0];
        int smax = -1;
        for(int i=1;i<length;i++){
            if(max<arr[i]){
                smax = max;
                max = arr[i];
            }
            else if(smax < arr[i] && arr[i] != max)smax = arr[i];
        }
        return smax;
    }
};