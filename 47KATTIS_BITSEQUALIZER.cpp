#include <bits/stdc++.h>
// #include <thread>
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
    int t;
    cin >> t;
    for(int tst = 1;tst<=t;tst++){
        string S,T;
        cin >> S >> T;
        int q0 = 0, q1 = 0, ne1 = 0, ne0 = 0;
        for(int i=0;i<S.length();++i){
            if(S[i] == '?')
                (T[i] == '0') ? q0++: q1++;
            else if(T[i] != S[i])
                (S[i] == '0')? ne0++ : ne1++ ;
        }
        int result = -1;
        result = min(ne0, ne1);
        ne0 -= result;
        ne1 -= result;
        if(ne0 > 0)
            result += ne0;
        if(ne1 > q1)
            result = -1;
        else{
            result += ne1;
            result += q1 + q0;
        }
        cout<<"Case "<<tst<<": "<<result<<'\n';
    }
}