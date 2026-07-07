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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL,*curr=head,*Next=head;
        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum1 = 0;
        int sum2 = 0;
        int place = 1;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1!=NULL){
            sum1+=(temp1->val*place);
            place*=10;
            temp1=temp1->next;
        }
        place=1;
        while(temp2!=NULL){
            sum2+=(temp2->val*place);
            place*=10;
            temp2=temp2->next;
        }
        int ans=sum1+sum2;
        int n = ans;
        int count=0;
        while(ans>0){
            ans=ans/10;
            count++;
        }
        if(count==0)count=1;
        ListNode* farzi = new ListNode(INT_MAX);
        ListNode* dummy = farzi;
        while(count>0){
            int val = n%10;
            ListNode* help = new ListNode(val);
            dummy->next=help;
            dummy=dummy->next;
            n/=10;
            count--;
        }
        return farzi->next;
    }
};