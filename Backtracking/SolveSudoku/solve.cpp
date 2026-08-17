#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInSafeState(vector<vector<char>>& board, int r, int c, char val){
        for(int i=0;i<9;i++){
            if(board[i][c] == val)return false;
        }
        for(int j=0;j<9;j++){
            if(board[r][j] == val)return false;
        }
        int sr = (r/3) * 3;
        int sc = (c/3) * 3;
        for(int i = sr;i < sr+3;i++){
            for(int j = sc;j< sc+3;j++){
                if(board[i][j]==val)return false;
            }
        }
        return true;
    }
    bool solveBack(vector<vector<char>>& board, int r, int c){
        if(r==9)return true;
        else if(c==9)return solveBack(board,r+1,0);
        else if(board[r][c]!='.')return solveBack(board,r,c+1);
        for(int j=0;j<9;j++){
            if(checkInSafeState(board,r,c,char('1' + j))){
                board[r][c] = char('1' + j);
                if(solveBack(board,r,c+1))return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveBack(board,0,0);
    }
};