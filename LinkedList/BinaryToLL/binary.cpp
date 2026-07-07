#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
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
    int getDecimalValue(ListNode* head) {

        int n = 0;
        int place = 1;
        ListNode* temp = reverse(head);
        while(temp!=NULL){
            n += (place*temp->val);
            temp = temp->next;
            place*=2;
        }
        return n;
    }
};