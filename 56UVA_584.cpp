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
int getNum(char x){
    return (x >= '0' && x <= '9') ? x - '0' : 10;
}
int findSum(string &game, int index, int frame){
    if(index < game.length() - 1){
        char throw1 = game[index];
        char throw2 = game[index + 2];
        if(throw1 >= '0' && throw1 <= '9' && throw2 >= '0' && throw2 <= '9'){
            return getNum(throw1) + getNum(throw2) + findSum(game, index + 4, frame + 1);
        }
        else if(throw1 == 'X'){
            int val = 10;
            if(frame < 10){
                if(game[index + 4] == '/')
                    val += 10;
                else
                    val += getNum(throw2) + getNum(game[index + 4]);
            }

            return val + findSum(game, index + 2, frame + 1);
        }
        else if(throw2 == '/'){
            int val = 10;
            if(frame < 10)
                val += getNum(game[index + 4]);
            return val + findSum(game, index + 4, frame + 1);
        }
    }
    else if(index == game.length() - 1){
        return getNum(game[index]);
    }
    return 0;
}
int main(){
    string game;
    while(getline(cin, game) && game != "Game Over"){
        cout<<findSum(game, 0, 1) << '\n';
    }
}

/*
    (No grid)
    0 * 0 => 0
    
    (only Corners exist)
    1 * N => 0
    N * 1 => 0 
    2 * N => 0
    N * 2 => 0 
    
    3 * N => N / 3
    M * 3 => M / 3

    4 * 4 => XXXX
             XSCX
             XCCX
             XXXX => 1
    
    5 * 4 => XXXX
             XSCX
             XCCX
             XSCX
             XCCX => (1 * 5/3) + 1
    
    12 * 7 =>XXXXXXX    XXXXXXX
             XCSCSCX    XCCCCCX
             XCCCCCX    XSCSCSX
             XCSCSCX => XCCCCCX 
             XCCCCCX    XSCSXSX
             XCSCSCX    XCCCCCX
             XCCCCCX
             XCSCSCX
             XCCCCCX
             XCSCSCX    XSCSXSX
             XXXXXXX    XXXXXXX
             
             min((N / 3) * ((M - 2) / 2)
             (M / 3) * ((N - 2) / 2)

             XXXXXXX M(7) * N(7)                
             XCCCCCX => (N/3) * (7/3) = 4
             XCSCSCX => (2 * 2) = 4
             XCCCCCX
             XCCCCCX
             XCSCSCX
             XCCCCCX
             
     
*/