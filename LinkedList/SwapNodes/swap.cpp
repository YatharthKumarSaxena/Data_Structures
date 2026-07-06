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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }
        int a = k;
        int b = n-k+1;
        if(a==b)return head;
        temp =head;
        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;
        n=1;
        while(temp!=NULL){
            if(n==a)temp1=temp;
            else if(n==b)temp2=temp;
            temp = temp->next;
            n++;
        }
        a = temp1->val;
        temp1->val = temp2->val;
        temp2->val = a;
        return head;
    }
};