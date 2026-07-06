#include <iostream>

class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        if(head == NULL)return 0;
        if(head->next == head)return 1;
        if(head->next == NULL)return 0;
        int ans = 0;
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)break;
        }
        if(slow == fast){
            ans = 1;
            slow = slow->next;
            while(slow != fast){
                ans++;
                slow = slow->next;
            }
        }
        return ans;
    }
};