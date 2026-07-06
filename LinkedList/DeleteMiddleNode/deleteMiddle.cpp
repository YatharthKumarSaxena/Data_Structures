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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)return NULL;
        ListNode* temp = head;
        int n = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        if(n%2==0){
            while(fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        else{
            while(fast->next->next->next){
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        slow->next = slow->next->next;
        return head;
    }
};