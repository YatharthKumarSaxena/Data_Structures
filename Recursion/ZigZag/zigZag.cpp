#include <iostream>
using namespace std;

class Solution {
public:
    void zigZag(int n) {
        if(n==0)return;
        cout<<n;
        zigZag(n-1);
        cout<<n;
        zigZag(n-1);
        cout<<n;
    }
};