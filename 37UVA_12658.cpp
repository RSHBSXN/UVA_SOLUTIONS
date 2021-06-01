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
int isOne(MATRIX(char) &MAT, int pos){
    for(int i=0;i<5;++i)
    {
        if(MAT[i][pos+1] != '*')
            return 0;
    }
    return 1;
}
int isTwoOrThree(MATRIX(char) &MAT, int pos){
    for(int r=0;r<5;r += 2){
        for(int c=pos;c<pos+3;c++){
            if(MAT[r][c] != '*')
                return 0;
        }
    }
    if(MAT[1][pos+2] != '*')
        return 0;
    
    int countStr = 0;
    for(int c=pos;c<pos+3;++c){
        if(MAT[3][c] == '*')
            countStr++;
    }
    if(countStr != 1)
        return 0;
    else if(MAT[3][pos] == '*')
        return 2;
    else if(MAT[3][pos+2] == '*')
        return 3;
    else
        return 0;
}
int isThree(MATRIX(char) &MAT, int pos){
    for(int i=0;i<5;++i)
    {
        if(MAT[i][pos+1] != '*')
            return 0;
    }
    return true;
}
int returnNumber(MATRIX(char) &MAT, int pos){
    return isOne(MAT, pos) + isTwoOrThree(MAT, pos);
}
int main(){
    int N;
    cin >> N;
    MATRIX(char) MAT(5, v(char)(N*4));
    for(int i=0;i<5;++i){
        for(int j=0;j < 4*N;++j){
            cin >> MAT[i][j];
        }
    }
    for(int pos=0;pos<4*N;pos+=4)
        cout<<returnNumber(MAT, pos);
    cout<<'\n';
}
