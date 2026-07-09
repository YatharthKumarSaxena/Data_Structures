#include <stack>
using namespace std;

class MinStack1 {
public:
    stack<int>helper;
    stack<int>st;
    MinStack1() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            helper.push(value);
            return;
        }
        int val = helper.top();
        if(val > value){
            helper.push(value);
        }
        else{
            helper.push(val);
        }
        st.push(value);
        return;
    }
    
    void pop() {
        if(st.empty())return;
        st.pop();
        helper.pop();
        return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return helper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */