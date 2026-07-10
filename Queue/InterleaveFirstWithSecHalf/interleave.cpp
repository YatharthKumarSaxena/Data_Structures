//User function Template for C++
#include <queue>
using namespace std;

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int oddIdx = 1;
        int evenIdx = 0;
        int count = 0;
        int n = q.size();
        vector<int>ans(n);
        while(count<n){
            if(count<n/2){
                ans[evenIdx]=q.front();
                evenIdx+=2;
            }
            else{
                ans[oddIdx]=q.front();
                oddIdx+=2;
            }
            q.pop();
            count++;
        }
        return ans;
    }
};