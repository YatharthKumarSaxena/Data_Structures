#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int rem=n%k;
        vector<ListNode*>ans;
        temp = head;
        while(temp!=NULL){
            ListNode* tempC = new ListNode(100);
            ListNode* c = tempC;
            int size=n/k;
            if(rem>0)size++;
            rem--;
            for(int i=1;i<=size;i++){
                tempC->next=temp;
                temp=temp->next;
                tempC=tempC->next;
            }
            tempC->next=NULL;
            ans.push_back(c->next);
        }
        if(ans.size()<k)while(ans.size()<k)ans.push_back(NULL);
        return ans;
    }
};