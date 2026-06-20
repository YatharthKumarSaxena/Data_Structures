#include <cmath>
using namespace std;

class Solution1 {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1;
        for(int i=2;i<sqrt(num);i++){
            if(num%i==0 and num/i != i)sum=(sum+i+num/i);
        }
        if(int(sqrt(num))*int(sqrt(num)==num))sum+=sqrt(num);
        return (sum==num);
    }
};

class Solution2 {
public:
    bool checkPerfectNumber(int num) {
        if (num==1) return false;
        int factorSum = 0;
        for(int i=1;i<sqrt(num);i++)
            if(num % i == 0) factorSum += i;
        for(int i=sqrt(num);i>1;i--)
            if(num % (num/i) == 0) factorSum += (num/i);
        if (factorSum == num) return true;
        return false;
    }
};
