#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* ans = new Node(head->val);
        Node* maker = ans;
        Node* temp = head->next;
        while(temp){
            Node* newNode = new Node(temp->val);
            maker->next = newNode;
            maker = maker->next;
            temp = temp->next;
        }
        unordered_map<Node*,Node*>mp;
        Node* tempA = head;
        Node* tempB = ans;
        while(tempA){
            mp[tempA] = tempB;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        tempA = head;
        tempB = ans;
        while(tempA){
            if(tempA->random)tempB->random = mp[tempA->random];
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return ans;
    }
};