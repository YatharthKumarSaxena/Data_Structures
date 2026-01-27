#include <cmath>

class Solution {
public:
    bool checkPerfectSquare(int num){
        int root = sqrt(num);
        if(root*root == num)return true;
        return false;
    }
    int makePerfectSquare(int n){
        int root = sqrt(n);
        return root*root;
    }
    bool judgeSquareSum(int c) {
        int a = 0;
        int b = c;
        while(a<=b){
            if(checkPerfectSquare(a) && checkPerfectSquare(b))return true;
            else if(!checkPerfectSquare(b)){
                b = makePerfectSquare(b);
                a = c-b;
            }else {
                a = (int)(sqrt(a)+1)*(int)(sqrt(a)+1);
                b = c-a;
            }
        }
        return false;
    }
};