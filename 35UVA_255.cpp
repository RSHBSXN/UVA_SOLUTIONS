#if __APPLE__
    #include <iostream>
    #include <vector>
    #include <map>
    #include <set>
    #include <string>
    #include <algorithm>
#else
    #include <bits/stdc++.h>
#endif
using namespace std;
#define ll long long
#define xll __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define v(type) vector<type>
#define MATRIX(type) v(v(type))
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PREC 1e-9
pii stateToPos(int state){
    pii pos;
    pos.first = state / 8;
    pos.second = state % 8;
    return pos;
}
vector<pii> adjc = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
string check(pii king, pii queen, pii dest){
    if(king == queen)
        return "Illegal state";
    else if((dest.first != queen.first && dest.second != queen.second)
            || (dest == queen)
            || ((dest.first == king.first && king.second >= min(dest.second, queen.second) && king.second <= max(dest.second, queen.second)))
            || ((dest.second == king.second && king.first >= min(dest.first, queen.first) && king.first <= max(dest.first, queen.first))))
        return "Illegal move";
    else{
        bool freeMove = false;
        for(pii &move : adjc){
            pii newC = {king.first + move.first, king.second + move.second};
            if(newC.first < 0 || newC.first > 7 || newC.second < 0 || newC.second > 7)
                continue;
            if(newC == dest)
                return "Move not allowed";
            if(newC.first != dest.first && newC.second != dest.second)
                freeMove = true;
        }
        return freeMove ? "Continue" : "Stop";
    }
}
int main(){
    int stateK, stateQ, destQ;
    while(cin >> stateK >> stateQ >> destQ){
        pii posK = stateToPos(stateK), posQ = stateToPos(stateQ), finQ = stateToPos(destQ);
        cout<<check(posK, posQ, finQ)<<'\n';
    }
}
