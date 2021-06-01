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
    while(true){
        int L;
        cin >> L;
        if(L == 0)
            break;
        string str = "+x";
        for(int i=L-1;i>=1;--i){
            string dec;
            cin >> dec;
            if(dec != "No"){
                if(str[1] == 'x'){
                    if(str[0] == dec[0])
                        str = string("+") + dec[1];
                    else
                        str = string("-") + dec[1];
                }
                else if(str[1] == dec[1]){
                    str = (str[0] == dec[0]) ? "-x" : "+x";
                }
            }
        }
        cout<<str<<'\n';
    }
}
