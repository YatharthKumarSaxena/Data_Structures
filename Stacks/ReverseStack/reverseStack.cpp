#include <stack>
#include <vector>
using namespace std;

class Solution1 {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        stack <int> st1,st2;
        while(!st.empty()){
            int val = st.top();
            st.pop();
            st1.push(val);
        }
        while(!st1.empty()){
            int val = st1.top();
            st1.pop();
            st2.push(val);
        }
        while(!st2.empty()){
            int val = st2.top();
            st2.pop();
            st.push(val);
        }
        return;
    }
};

class Solution2 {
  public:
    void insertAtBottom(stack<int> & st, int x) {
        if(st.size()==0){
            st.push(x);
            return;
        }
        int val = st.top();
        st.pop();
        insertAtBottom(st,x);
        st.push(val);
    }
    void reverseStack(stack<int> &st) {
        // code here
        if (st.empty()) return;
    
        int val = st.top();
        st.pop();
    
        reverseStack(st);
        insertAtBottom(st, val);

    }
};