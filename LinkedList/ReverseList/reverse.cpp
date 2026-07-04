#include <iostream>

class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};


class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        if(!head || !head->next)return head;
        Node* newHeadNode = reverseList(head->next);\
        head->next->next = head;
        head->next = NULL;
        return newHeadNode;
    }
};