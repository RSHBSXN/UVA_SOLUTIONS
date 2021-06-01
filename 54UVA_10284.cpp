/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define xll __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define v(x) vector<x>
#define MATRIX(x) vector<vector<x>>
#define MATRIX3D(x) vector<vector<vector<x>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PREC 1e-9
bool isSafe(int x ,int y){
    return x>=0 && x < 8 && y >=0 && y <8;
}
void handleDiag(vector<string> &board, vector<string> &board2, int i, int j){
    bool dRD = true, dRU  = true, dLD = true, dLU = true;
    for(int d = 1; isSafe(i + d, j + d) || isSafe(i - d, j - d) || isSafe(i + d, j - d) || isSafe(i - d, j + d);d++){
        if(isSafe(i + d, j + d)){
            if(dRD && board[i + d][j + d] == '.')
                board2[i + d][j + d] = 'X';
            else if(dRD)
                dRD = false;
        }
        if(isSafe(i - d, j - d)){
            if(dRU && board[i - d][j - d] == '.')
                board2[i - d][j - d] = 'X';
            else if(dRU)
                dRU = false;
        }
        if(isSafe(i + d, j - d)){
            if(dLD && board[i + d][j - d] == '.')
                board2[i + d][j - d] = 'X';
            else if(dLD)
                dLD = false;
        }
        if(isSafe(i - d, j + d)){
            if(dLU && board[i - d][j + d] == '.')
                board2[i - d][j + d] = 'X';
            else if(dLU)
                dLU = false;
        }
    }    
                    
}
void handleVert(vector<string> &board, vector<string> &board2, int i, int j){
    bool up = true, down = true;
    for(int d = 1; isSafe(i + d, j) || isSafe(i - d, j); ++d){
        if(isSafe(i + d, j)){
            if(down && board[i + d][j] == '.')
                board2[i+d][j] = 'X';
            else if(down)
                down = false;
        }
        if(isSafe(i - d, j)){
            if(up && board[i - d][j] == '.')
                board2[i-d][j] = 'X';
            else if(up)
                up = false;
        }
    }
}
void handleHor(vector<string> &board, vector<string> &board2, int i, int j){
    bool left = true, right = true;
    for(int d = 1; isSafe(i, j + d) || isSafe(i, j - d);++d){
        if(isSafe(i, j + d)){
            if(right && board[i][j + d] == '.')
                board2[i][j+d] = 'X';
            else if(right)
                right = false;
        }
        if(isSafe(i, j - d)){
            if(left && board[i][j - d] == '.')
                board2[i][j - d] = 'X';
            else if(left)
                left = false;
        }
    }
}
int main(){
    string fen;
    FASTIO;
    vector<pair<int,int>> knightMoves = {{1,2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
    vector<pair<int,int>> kingMoves = {{0,1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    while(cin >> fen){
        stringstream buff(fen);
        vector<string> board(8, "........");
        string str;
        int row = 0;
        while(getline(buff, str, '/')){
            int col = 0;
            for(char x : str){
                if(x >= '1' && x <= '8')
                    col += x - '0';
                else{
                    board[row][col] = x;
                    col++;
                }
            }
            row++;
        }
        vector<string> board2(board);
        for(int i=0;i<8;++i){
            for(int j=0;j<8;++j){
                if(board[i][j] == 'Q' || board[i][j] == 'q'){
                    handleDiag(board, board2, i, j);
                    handleVert(board, board2, i, j);
                    handleHor(board, board2, i, j);
                }
                else if(board[i][j] == 'P' || board[i][j] == 'p'){
                    int r = (board[i][j] == 'P') ? -1 : +1;
                    if(i + r >= 0 && i + r < 8){
                        if(j + 1 < 8 && board[i + r][j+1] == '.')
                            board2[i+r][j+1] = 'X';
                        if(j - 1 >= 0 && board[i + r][j-1] == '.')
                            board2[i+r][j-1] = 'X';
                    }
                }
                else if(board[i][j] == 'N' || board[i][j] == 'n'){
                    for(pair<int,int> &mv : knightMoves){
                        int newR = i + mv.first, newC = j + mv.second;
                        if(isSafe(newR, newC) && board[newR][newC] == '.')
                            board2[newR][newC] = 'X';
                    }
                }
                else if(board[i][j] == 'B' || board[i][j] == 'b'){
                    handleDiag(board, board2, i, j);
                }
                else if(board[i][j] == 'R' || board[i][j] == 'r'){
                    handleVert(board, board2, i, j);
                    handleHor(board, board2, i, j);
                }
                else if(board[i][j] == 'K' || board[i][j] == 'k'){
                    for(pair<int,int> &mv : kingMoves){
                        if(isSafe(i + mv.first, j + mv.second) && board[i + mv.first][j + mv.second] == '.')
                            board2[i + mv.first][j + mv.second] = 'X';
                    }                    
                }
            }
        }
        int count = 0;
        for(int i=0;i<8;++i){
            for(int j=0;j<8;++j){
                if(board2[i][j] == '.')
                    count++;
            }
        }
        cout<<count<<'\n';
    }
}
