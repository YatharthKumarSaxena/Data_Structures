#include <vector>
using namespace std;

// Using Two Pass Method

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int no0 = 0;
        int no1 = 0;
        int no2 = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0)no0++;
            else if(arr[i]==1)no1++;
            else no2++;
        }
        int idx = 0;
        for(int i=0;i<no0;i++){
            arr[idx++] = 0;
        }
        for(int i=idx;i<idx+no1;i++){
            arr[i] = 1;
        }
        idx+=no1;
        for(int i=idx;i<arr.size();i++){
            arr[i] = 2;
        }
    }
};