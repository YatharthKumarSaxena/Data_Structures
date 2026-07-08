#include <stack>
using namespace std;

class Solution1 {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        stack<int>st1;
        while(!st.empty()){
            int val = st.top();
            st.pop();
            st1.push(val);
        }
        st.push(x);
        while(!st1.empty()){
            int val = st1.top();
            st1.pop();
            st.push(val);
        }
        return st;
    }
};

class Solution2 {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        if(st.size()==0){
            st.push(x);
            return st;
        }
        int val = st.top();
        st.pop();
        st = insertAtBottom(st,x);
        st.push(val);
        return st;
    }
};