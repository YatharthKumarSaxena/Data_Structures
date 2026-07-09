#include <iostream>

class Node{
public:
    Node* next;
    Node* prev;
    int val;
    Node(int val){
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};
class MyCircularDeque {
public:
    Node* head;
    Node* tail;
    int size;
    int capacity;
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    bool insertFront(int value) {
        if(size==capacity)return false;
        Node* temp = new Node(value);
        if(size==0){
            head = temp;
            tail = temp;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==capacity)return false;
        Node* temp = new Node(value);
        if(size==0){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0)return false;
        else if(size==1){
            head = NULL;
            tail = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete(temp);
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size==0)return false;
        else if(size==1){
            head = NULL;
            tail = NULL;
        }
        else{
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete(temp);
        }
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0)return -1;
        return head->val;
    }
    
    int getRear() {
        if(size==0)return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        if(size)return false;
        return true;
    }
    
    bool isFull() {
        if(size==capacity)return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */