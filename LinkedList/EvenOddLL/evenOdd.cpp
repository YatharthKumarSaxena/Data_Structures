struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* tempOdd = oddHead;
        ListNode* tempEven = evenHead;
        while(tempOdd->next && tempOdd->next->next){
            tempOdd->next = tempOdd->next->next;
            tempEven->next = tempEven->next->next;
            tempOdd = tempOdd->next;
            tempEven = tempEven->next;
        }
        tempOdd->next = evenHead;
        return oddHead;
    }
};