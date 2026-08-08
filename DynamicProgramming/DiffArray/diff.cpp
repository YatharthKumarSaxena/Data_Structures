#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> diffArray(vector<int>& arr, vector<vector<int>>& opr) {
        // code here
        int n = arr.size();
        vector<int>diff(n+1,0);
        int ops = opr.size();
        for(int i=0;i<ops;i++){
            int L = opr[i][0];
            int R = opr[i][1];
            int V = opr[i][2];
            diff[L] += V;
            diff[R+1] -= V;
        }
        for(int i=1;i<n;i++){
            diff[i] += diff[i-1];
        }
        for(int i=0;i<n;i++){
            diff[i] += arr[i];
        }
        diff.pop_back();
        return diff;
    }
};