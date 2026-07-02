#include <iostream>

 struct ListNode {
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next) return head;
        int listSize = 0;
        ListNode* temp = head;
        ListNode* tail = NULL;
        while (temp){
            tail = temp;
            temp = temp->next;
            listSize += 1;
        }
        k = k%listSize;
        temp = head;
        for(int i=0;i<listSize-k-1;i++){
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};