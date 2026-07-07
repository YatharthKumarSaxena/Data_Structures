#include <iostream>
#include <vector>
#include <climits>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        if(n<=3)return {-1,-1};
        vector<int>v;
        ListNode* help = head;
        temp = head->next;
        n=2;
        while(temp->next!=NULL){
            if(help->val<temp->val && temp->val>temp->next->val)v.push_back(n);
            else if(help->val>temp->val && temp->val<temp->next->val)v.push_back(n);
            n++;
            help=help->next;
            temp=temp->next;
        }
        if(v.size()==1 ||v.size()==0)return {-1,-1};
        if(v.size()==2){
            int res = v[1]-v[0];
            return {res,res};
        }
        vector<int>ans(2);
        ans[1]=v[v.size()-1]-v[0];
        ans[0]=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            ans[0]=min(ans[0],v[i+1]-v[i]);
        }
        return ans;
    }
};