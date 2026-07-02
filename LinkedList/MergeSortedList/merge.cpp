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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ans = NULL;
        ListNode *a = list1;
        ListNode *b = list2;
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;
        if (a->val < b->val)
        {
            ans = a;

            a = a->next;
        }
        else
        {
            ans = b;
            b = b->next;
        }
        ListNode *temp = ans;
        while (a && b)
        {
            if (a->val < b->val)
            {
                temp->next = a;
                a = a->next;
            }
            else
            {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        if (b)
            temp->next = b;
        if (a)
            temp->next = a;
        return ans;
    }
};