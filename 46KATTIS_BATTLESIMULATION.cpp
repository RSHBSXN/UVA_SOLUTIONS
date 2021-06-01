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
int main(){
    string moves, counter;
    cin >> moves;
    map<char, int> MAP;
    for(int i=0;i<min(3, (int) moves.size());++i)
        MAP[moves[i]]++;
    for(int i=0, j = 3;i<moves.length();){
        if(MAP.size() == 3){
            counter += "C";
            MAP.clear();
            for(int k = j;k<min(j+3, (int)moves.size());++k){
                MAP[moves[k]]++;
            }
            i = j;
            j = i + 3;
        }
        else{
            switch(moves[i]){
                case 'R':
                    counter += "S";
                    break;
                case 'B':
                    counter += "K";
                    break;
                case 'L':
                    counter += "H";
                    break;
            }
            MAP[moves[i]]--;
            if(j < moves.length())
                MAP[moves[j]]++;
            if(MAP[moves[i]] == 0)
                MAP.erase(moves[i]);
            i++;
            j++;
        }
    }
    cout<<counter<<'\n';
}
