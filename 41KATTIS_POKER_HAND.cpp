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
    unordered_map<char, int> MAP;
    int inp = 0;
    while(inp++ < 5){
        string card;
        cin >> card;
        MAP[card[0]]++;
    }
    int maxF = 1;
    for(auto &face : MAP){
        maxF = max(face.second, maxF);
    }
    cout<<maxF<<'\n';
}