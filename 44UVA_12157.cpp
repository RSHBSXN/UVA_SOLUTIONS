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
    int T;
    cin >> T;
    for(int i=1;i<=T;++i){
        int calls;
        cin >> calls;
        int totalMile = 0, totalJuice = 0;
        while(calls--){
            int call;
            cin >> call;
            totalMile += ((call/30) + 1) * 10;
            totalJuice += ((call/60) + 1) * 15;
        }
        cout<<"Case "<<i<<": ";
        if(totalMile <= totalJuice)
            cout<<"Mile ";
        if(totalJuice <= totalMile)
            cout<<"Juice ";
        cout<<min(totalMile, totalJuice)<<'\n';
    }
}
