#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> npe(n);
        vector<int> nge(n);
        int max = -1;
        for(int i=0;i<n;i++){
            npe[i] = max;
            if(max < arr[i])max = arr[i];
        }
        max = -1;
        for(int j=n-1;j>=0;j--){
            nge[j] = max;
            if(max < arr[j])max = arr[j];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            nge[i] = min(nge[i], npe[i]);
        }
        for(int i=0;i<n;i++){
            if(nge[i]>arr[i])ans += (nge[i]-arr[i]);
        }
        return ans;
    }
};