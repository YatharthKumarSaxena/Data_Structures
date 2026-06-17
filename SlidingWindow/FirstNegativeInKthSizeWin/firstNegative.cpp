#include <vector>
#include <queue>
using namespace std;

class Solution1 {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        vector<int>ans(n-k+1,0);
        int negIdx = -1;
        for(int i=0;i<k;i++){
            if(arr[i]<0){
                negIdx = i;
                ans[0] = arr[i];
                break;
            }
        }
        for(int i=1;i<n-k+1;i++){
            if(negIdx >= i){
                ans[i] = arr[negIdx];
            }else{
                negIdx = -1;
                int p = i;
                while(p<i+k){
                    if(arr[p]<0){
                        negIdx = p;
                        ans[i] = arr[negIdx];
                        break;
                    }
                    p++;
                }
            }
        }
        return ans;
    }
};


class Solution2 {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        vector<int>ans(n-k+1,0);
        queue<int>qu;
        for(int i=0;i<n;i++){
            if(arr[i]<0)qu.push(i);
        }
        int negIdx = -1;
        for(int i=0;i<k;i++){
            if(arr[i]<0){
                negIdx = i;
                ans[0] = arr[i];
                break;
            }
        }
        for(int i=1;i<n-k+1;i++){
            if(negIdx >= i){
                ans[i] = arr[negIdx];
            }else{
                while(!qu.empty() && qu.front()<i){
                    qu.pop();
                }
                if(!qu.empty() && qu.front()>=i && qu.front()<i+k){
                    negIdx = qu.front();
                    ans[i] = arr[negIdx];
                }
            }
        }
        return ans;
    }
};