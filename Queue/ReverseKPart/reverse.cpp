#include <queue>
#include <stack>
using namespace std;

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(k<=1)return q;
        stack<int> st;
        int n = q.size();
        if(k>n)return q;
        int count = k;
        while(count){
            int val = q.front();
            st.push(val);
            q.pop();
            count--;
        }
        while(!st.empty()){
            int val = st.top();
            q.push(val);
            st.pop();
        }
        count = n-k;
        while(count){
            int val = q.front();
            q.push(val);
            q.pop();
            count--;
        }
        return q;
    }
};