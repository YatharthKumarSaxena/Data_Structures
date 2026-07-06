#include <iostream>
#include <climits>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* farzi = new ListNode(INT_MAX);
        ListNode* dummy = farzi;
        ListNode* temp = head;
        while(temp!=NULL){
            int value = temp->val;
            if(value!=val){
                ListNode* help = new ListNode(value);
                farzi->next = help;
                farzi = farzi->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};