#include <vector>
using namespace std;

class Solution {
  public:
    int multiplyRowCol(int r, int c, vector<vector<int>>& mat1, vector<vector<int>>& mat2){
        int n = mat1.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += mat1[r][i]*mat2[i][c];
        }
        return ans;
    }
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        // Code here
        int n = mat1.size();
        vector<vector<int>>ans(n, vector<int> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = multiplyRowCol(i,j,mat1,mat2);
            }
        }
        return ans;
    }
};