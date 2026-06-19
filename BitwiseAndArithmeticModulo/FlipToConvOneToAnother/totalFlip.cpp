class Solution {
public:
    int minBitFlips(int start, int goal) {
        int setBitVal = start^goal;
        return __builtin_popcount(setBitVal);
    }
};