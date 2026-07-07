#include <iostream>
#include <climits>
using namespace std;

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
    int pairSum(ListNode* head) {
        int maxSum = INT_MIN;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }
        temp = head;
        ListNode* help = head;
        int check = n;
        while(help){
            if(n==check/2)break;
            help = help->next;
            n--;
        }
        help = reverse(help);
        while(help){
            maxSum = max(help->val+temp->val,maxSum);
            help = help->next;
            temp = temp->next;
        }
        return maxSum;
    }
};