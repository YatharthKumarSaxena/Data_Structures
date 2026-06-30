#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if (hasCycle(head)){
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast and fast->next){
                slow = slow->next;
                fast = fast->next->next;
                if (slow==fast) break;
            }
            ListNode* temp = head;
            while (temp){
                if(temp == slow) return temp;
                slow = slow->next;
                temp = temp->next;
            }
        }
        return NULL;
    }
};