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
bool checkLDiag(MATRIX(int) &BINGO){
    for(int i=0;i<5;++i){
        if(BINGO[i][i] != 0){
            return false;
        }
    }
    return true;
}
bool checkRDiag(MATRIX(int) &BINGO){
    for(int i=0,j = 4;i<5;++i,--j){
        if(BINGO[i][j] != 0){
            return false;
        }
    }
    return true;
}
bool checkHorVert(MATRIX(int) &BINGO){
    bool allCrossed = false;
    for(int r=0;r<5 && !allCrossed;++r){
        allCrossed = true;
        for(int c=0;c<5;++c){
            if(BINGO[r][c] != 0){
                allCrossed = false;
                break;
            }
        }
        if(!allCrossed){
            allCrossed = true;
            for(int c=0;c<5;++c){
                if(BINGO[c][r] != 0){
                    allCrossed = false;
                    break;
                }
            }
        }
    }
    return allCrossed;
}
bool isBingo(MATRIX(int) &BINGO){
    return checkLDiag(BINGO) || checkRDiag(BINGO) || checkHorVert(BINGO);
}
int main(){
    int n;
    cin >> n;
    while(n--){
        MATRIX(int) BINGO(5, v(int)(5));
        for(int i=0;i<5;++i){
            for(int j=0;j<5;++j){
                if(i == 2 && j == 2)
                    BINGO[i][j] = 0;
                else
                    cin >> BINGO[i][j];
            }
        }
        int announced = 0;
        bool gotBingo = false;
        for(int i=1;i<=75;++i){
            int number;
            cin >> number;
            if(!gotBingo){
                announced++;
                int col = number / 15;
                if(number % 15 == 0)
                    col--;
                
                for(int r=0;r<5;++r){
                    if(BINGO[r][col] == number){
                        BINGO[r][col] = 0;
                        break;
                    }
                }
                gotBingo = isBingo(BINGO);
            }
        }
        cout<<"BINGO after "<<announced<<" numbers announced\n";
    }
}
