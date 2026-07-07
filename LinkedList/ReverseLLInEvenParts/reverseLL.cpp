#include <iostream>

struct ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* Next = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    ListNode* reversePart(ListNode*  head,int left,int right){
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        int n = 1;
        while(temp){
            if(left-1==n)a = temp;
            else if(left==n)b = temp;
            else if(right==n)c = temp;
            else if(right+1==n)d = temp;
            temp = temp->next;
            n++;
        }
        if(a)a->next = NULL;
        c->next = NULL;
        c = reverse(b);
        if(a)a->next = c;
        b->next = d;
        if(a)return a;
        return c;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int gap = 1;
        ListNode* temp = head;
        while(temp && temp->next){
            ListNode* t = temp->next;
            int remLen = 0;
            for(int i=1;i<=gap+1 && t!=NULL;i++){
                t=t->next;
                remLen++;
            }
            if(remLen<gap+1)gap = remLen-1;
            if(gap%2!=0)reversePart(temp,2,gap+2);
            gap++;
            for(int i=1;temp!=NULL && i<=gap;i++){
                temp=temp->next;
            }
        }
        return head;
    }
};