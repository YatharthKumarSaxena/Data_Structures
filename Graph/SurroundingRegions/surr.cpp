#include <vector>
using namespace std;

class Solution {
public:
    void markAllRegion(vector<vector<char>>& board, int r,int c, char p,char x){
        int m = board.size();
        int n = board[0].size();
        if(r<0 || r>=m || c<0 || c>=n)return;
        else if(board[r][c]==p)return;
        else if(board[r][c]==x){
            board[r][c] = p;
            markAllRegion(board,r-1,c,p,x);
            markAllRegion(board,r+1,c,p,x);
            markAllRegion(board,r,c-1,p,x);
            markAllRegion(board,r,c+1,p,x);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        int m = board.size();
        int n = board[0].size();
        
        // 1. Traverse first and last column (dfs ki jagah apka markAllRegion call hoga)
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') markAllRegion(board, i, 0, '#', 'O');
            if(board[i][n - 1] == 'O') markAllRegion(board, i, n - 1, '#', 'O');
        }
        
        // 2. Traverse first and last row
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') markAllRegion(board, 0, j, '#', 'O');
            if(board[m - 1][j] == 'O') markAllRegion(board, m - 1, j, '#', 'O');
        }
        
        // 3. Process the entire board to finalize
        // Yeh step aapne bilkul theek likha tha! Yeh khud hi unmark aur surround dono kar dega.
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') {
                    // It was not connected to a boundary, so surround it
                    board[i][j] = 'X';
                } else if(board[i][j] == '#') {
                    // It was connected to a boundary, restore it (Unmark ho gaya)
                    board[i][j] = 'O';
                }
            }
        }
    }
};