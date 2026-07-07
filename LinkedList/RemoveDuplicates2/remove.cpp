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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode* sortMaker = NULL;
        ListNode* temp = head;
        while(temp && temp->next){
            if(temp->val == temp->next->val){
                int value = temp->val;
                while(temp && temp->val == value){
                    temp = temp->next;
                }
            }else{
                if(!sortMaker){
                    sortMaker = temp;
                    head = sortMaker;
                }
                else{
                    sortMaker->next = temp;
                    sortMaker = sortMaker->next;
                }
                if(temp)temp = temp->next;
            }
        }
        if(temp && sortMaker && sortMaker->val != temp->val)sortMaker->next = temp;
        else{ 
            if(!sortMaker && temp)return temp;
            else if (sortMaker) sortMaker->next = NULL;
            else return NULL;
        }
        return head;
    }
};