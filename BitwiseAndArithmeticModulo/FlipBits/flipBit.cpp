class Solution {
public:
    long long int flipBitsTillMSB(long long int N) {
        long long n = N;
        long long temp = n;

        // Highest set bit nikalna
        while (n) {
            temp = n;
            n &= (n - 1);
        }

        // Mask banana
        temp *= 2;
        temp -= 1;

        // Flip till MSB
        return N ^ temp;
    }
};