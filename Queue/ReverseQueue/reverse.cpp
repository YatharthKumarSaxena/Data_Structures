#include <queue>
#include <stack>
using namespace std;

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int>st;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            st.push(val);
        }
        while(!st.empty()){
            int val = st.top();
            st.pop();
            q.push(val);
        }
        return;
    }
};