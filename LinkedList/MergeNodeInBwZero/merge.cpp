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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        ListNode* curr = head->next;   // Skip first 0
        int sum = 0;

        while (curr) {

            if (curr->val == 0) {
                tail->next = new ListNode(sum);
                tail = tail->next;
                sum = 0;
            } else {
                sum += curr->val;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};