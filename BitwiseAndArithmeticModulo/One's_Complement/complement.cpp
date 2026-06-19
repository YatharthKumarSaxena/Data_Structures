class Solution {
public:
    int findComplement(int num) {
        int n = num;
        long temp = n;
        while(n){
            temp = n;
            n &= n-1;
        }
        temp = (temp*2)-1;
        return num^temp;
    }
};