#include <vector>
using namespace std;

class Solution {
public:
    void segregateElements(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        int idx = 0;
        for(int i=0;i<n;i++){
            if(arr[i]>=0)ans[idx++] = arr[i];
        }
        for(int i=0;i<n;i++){
            if(arr[i]<0)ans[idx++] = arr[i];
        }
        for(int i=0;i<n;i++){
            arr[i] = ans[i];
        }
    }
};
