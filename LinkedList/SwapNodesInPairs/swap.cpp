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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* tempOdd = oddHead;
        ListNode* tempEven = evenHead;
        while(tempOdd->next && tempOdd->next->next){
            tempOdd->next = tempOdd->next->next;
            tempEven->next = tempEven->next->next;
            tempOdd = tempOdd->next;
            tempEven = tempEven->next;
        }
        tempOdd->next = NULL;
        if (tempEven) tempEven->next = NULL;
        ListNode* temp = evenHead;
        ListNode* a = temp;
        ListNode* b = oddHead;
        ListNode* prev = NULL;
        while (temp){
            a = a->next;
            temp->next = b;
            prev = temp;
            temp = temp->next;
            if (b) b = b->next;
            if(temp){
                temp->next = a;
                prev = temp;
                temp = temp->next;
            }
        }
        if (b)prev->next = b;
        return evenHead;
    }
};