#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        if(k>n)return 0;
        int winSum = 0;
        for(int i=0;i<k;i++){
            winSum += arr[i];
        }
        int i=0;
        int j=k;
        int ans=0;
        while(j<n){
            int winAvg = winSum/k;
            if(winAvg>=threshold)ans++;
            winSum = winSum - arr[i] + arr[j];
            i++;
            j++;
        }
        if(winSum/k >= threshold)ans++;
        return ans;
    }
};