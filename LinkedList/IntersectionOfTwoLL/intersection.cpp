#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    int findLength(ListNode *head){
        ListNode* temp = head;
        int ans = 0;
        while(temp){
            ans++;
            temp = temp->next;
        }
        return ans;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = findLength(headA);
        int lenB = findLength(headB);
        int totalMoves = abs(lenA-lenB);
        if(lenA > lenB){
            for(int i=0;i<totalMoves;i++){
                headA = headA->next;
            }
        }
        else{
            for(int i=0;i<totalMoves;i++){
                headB = headB->next;
            }
        }
        while(headA){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};