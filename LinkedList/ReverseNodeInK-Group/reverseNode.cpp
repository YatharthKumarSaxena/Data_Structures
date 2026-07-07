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
        while(temp && n <= right){
            if(n == left-1) a = temp;
            else if(n == left) b = temp;
            else if(n == right) c = temp;

            temp = temp->next;
            n++;
        }
        d = c->next;
        c->next = NULL;
        ListNode* t = reverse(b);
        if (a) a->next = t;
        else head = t;
        b->next = d;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        if(!head || !head->next) return head;
        ListNode* temp = head;
        int first = 1;
        int last = k;
        ListNode* t = temp;
        while(temp){
            int remLen = 0;
            while(remLen < k && t){
                t=t->next;
                remLen+=1;
            }
            if(remLen == 0) break;
            if(remLen==k){
                temp = reversePart(temp,first,last);
                head = temp;
            }
            else break;
            first += k;
            last += k;
        }
        return head;
    }
};