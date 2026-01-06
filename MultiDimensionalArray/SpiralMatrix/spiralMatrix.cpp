#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int count = r*c;
        int minr = 0;
        int maxr = r-1;
        int minc = 0;
        int maxc = c-1;
        int tne = r*c;
        vector<int>ans(count);
        while(count>0){
            for(int i=minc;i<=maxc && count;i++){
                ans[tne-count] = matrix[minr][i];
                count--;
            }
            minr++;
            for(int i=minr;i<=maxr && count;i++){
                ans[tne-count] = matrix[i][maxc];
                count--;
            }
            maxc--;
            for(int i=maxc;i>=minc && count;i--){
                ans[tne-count] = matrix[maxr][i];
                count--;
            }
            maxr--;
            for(int i=maxr;i>=minr && count;i--){
                ans[tne-count] = matrix[i][minc];
                count--;
            }
            minc++;
        }
        return ans;
    }
};