#include <vector>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>helper(n,0);
        int idx = 0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0)helper[idx++] = arr[i];
        } 
        for(int i=0;i<n;i++){
            arr[i] = helper[i];
        }
    }
};