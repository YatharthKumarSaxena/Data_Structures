#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* Next = head;
    while(curr){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverse(head);
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        vector<int>ans(n);
        ans[n-1] = 0;
        stack<int>st;
        st.push(head->val);
        head = head->next;
        for(int i=n-2;i>=0;i--){
            while(st.size() && st.top()<=head->val)st.pop();
            if(st.size()==0)ans[i]=0;
            else ans[i]=st.top();
            st.push(head->val);
            head = head->next;
        }
        return ans;
    }
};