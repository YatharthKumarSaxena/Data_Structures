#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *head1, int a, int b, ListNode *head2)
    {
        ListNode *A = NULL;
        ListNode *B = NULL;
        ListNode *tail2 = NULL;
        ListNode *temp1 = head1;
        ListNode *temp2 = head2;
        // Finding the last node of list2
        while (temp2)
        {
            if (temp2->next == NULL)
                tail2 = temp2;
            temp2 = temp2->next;
        }
        // Finding the linking nodes of first list
        int n = 1;
        while (temp1)
        {
            if (a == n)
                A = temp1;
            else if (b + 2 == n)
                B = temp1;
            n++;
            temp1 = temp1->next;
        }
        A->next = head2;
        tail2->next = B;
        return head1;
    }
};