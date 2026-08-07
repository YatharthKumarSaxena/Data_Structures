class Solution {
public:
    double dp[30][30][105];
    double doDP(int r, int c, int k, int n){
        if(r<0 || r>=n || c<0 || c>=n)return 0.0;
        else if(k==0) return 1.0;
        else if(dp[r][c][k]>=0.0)return dp[r][c][k];
        int dir[8][2] = {{1,2},{-1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,1},{-2,-1}};
        double res = 0.0;
        for(int i=0;i<8;i++){
            int nr = r+dir[i][0];
            int nc = c+dir[i][1];
            if(nr>=0 && nr<n && nc>=0 && nc<n){
                res += doDP(nr,nc,k-1,n)*0.125;
            }
        }
        return dp[r][c][k] = res;;
    }
    double knightProbability(int n, int k, int row, int column) {
        for(int i=0;i<30;i++){
            for(int j=0;j<30;j++){
                for(int k=0;k<105;k++) dp[i][j][k] = -1.0;
            }
        }
        return doDP(row,column,k,n);
    }
};