#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // code here
        if(!head or !head->next) return head;
        int listSize = 0;
        Node* temp = head;
        Node* tail = NULL;
        while (temp){
            tail = temp;
            temp = temp->next;
            listSize += 1;
        }
        k = k%listSize;
        if (k == 0) return head;
        temp = head;
        for(int i=0;i<k-1;i++){
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};