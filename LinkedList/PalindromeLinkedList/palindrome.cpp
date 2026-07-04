#include <iostream>

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};

class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        Node* prev = NULL;
        Node* curr = head;
        Node* next = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(Node *head) {
        //  code here
        Node* slow = head;
        Node* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* temp1 = head;
        Node* temp2 = reverseList(slow->next);
        while(temp2){
            if(temp1->data != temp2->data)return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};