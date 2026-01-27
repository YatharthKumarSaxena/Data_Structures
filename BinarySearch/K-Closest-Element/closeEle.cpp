#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size()-1;
        if(x>arr[n]){
            return vector<int>(arr.begin()+n+1-k,arr.end());
        }
        if(x<arr[0]){
            return vector<int>(arr.begin(),arr.begin()+k);
        }
        int lo = 0;
        int hi = n;
        int idx = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(arr[mid]==x){
                idx = mid;
                break;
            }
            else if(arr[mid]<x) lo = mid+1;
            else hi = mid-1;
        }
        int lb;
        int ub;
        vector<int>ans;
        if(idx==-1){
            lb = hi;
            ub = lo;
        }else {
            lb = idx-1;
            ub = idx+1;
            ans.push_back(arr[idx]);
            k--;
        }
        while(k>0){
            if(ub==n+1){ // Use Only lb
                ans.push_back(arr[lb--]);
            }
            else if(lb==-1){ // Use Only ub
                ans.push_back(arr[ub++]);
            }
            else {
                int leftDis = abs(x-arr[lb]);
                int rightDis = abs(x-arr[ub]);
                if(leftDis<=rightDis){
                    ans.push_back(arr[lb--]);
                }else{
                    ans.push_back(arr[ub++]);
                }
            }
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};