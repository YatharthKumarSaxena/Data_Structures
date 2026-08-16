#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        priority_queue<int>pq;
        if(k<=2)return 1;
        int a=1;
        int b=1;
        pq.push(a);
        while(b<=k){
            int temp = b;
            b = a+b;
            a = temp;
            pq.push(b);
        }
        int ops = 0;
        while(k>0){
            int ele = pq.top();
            pq.pop();
            if(ele <= k){
                k -= ele;
                ops++;
            }
        }
        return ops;
    }
};