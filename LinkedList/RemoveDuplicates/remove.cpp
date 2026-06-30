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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *a = head;
        ListNode *b = head->next;
        while (b)
        {
            while (b && a->val == b->val)
            {
                b = b->next;
            }
            a->next = b;
            a = a->next;
            if (b)
                b = b->next;
        }
        return head;
    }
};