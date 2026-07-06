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
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        // a is the last node of first linked list
        // b is the first node of the second linked list that is to be reversed
        ListNode *a = NULL;
        ListNode *b = NULL;
        // c is the last node of the second linked list
        // d is the first node of the third linked list
        ListNode *c = NULL;
        ListNode *d = NULL;
        // Iterator node
        ListNode *temp = head;
        int n = 1;
        // Marking the location of each Node
        while (temp != NULL)
        {
            if (left - 1 == n)
                a = temp;
            if (left == n)
                b = temp;
            if (right == n)
                c = temp;
            if (right + 1 == n)
                d = temp;
            temp = temp->next;
            n++;
        }
        // Breaking the linked list into threee parts
        if (a)
            a->next = NULL;
        c->next = NULL;
        c = reverse(b);
        if (a)
            a->next = c;
        b->next = d;
        if (a)
            return head;
        return c;
    }
};