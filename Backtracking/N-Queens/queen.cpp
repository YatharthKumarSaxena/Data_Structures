#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInSafeState(vector<vector<char>>& board, int r, int c){
        int n = board.size();
        for(int i=0;i<n;i++){
            if(board[i][c]=='Q')return false;
        }
        for(int j=0;j<n;j++){
            if(board[r][j]=='Q')return false;
        }
        for(int i=r,j=c;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }
        for(int i=r,j=c;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    } 
    void doBacktrack(vector<vector<string>>& ans,vector<vector<char>>& board, int r){
        int n = board.size();
        if(r==n){
            vector<string>helper;
            for(int i=0;i<n;i++){
                string temp = "";
                for(int j=0;j<n;j++){
                    temp += board[i][j];
                }
                helper.push_back(temp);
            }
            ans.push_back(helper);
            return;
        }
        for(int c=0;c<n;c++){
            if(checkInSafeState(board,r,c)){
                board[r][c] = 'Q';
                doBacktrack(ans,board,r+1);
                board[r][c] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        doBacktrack(ans,board,0);
        return ans;
    }
};