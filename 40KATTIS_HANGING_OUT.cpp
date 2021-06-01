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
    int L,N;
    cin >> L >> N;
    int rejections = 0;
    while(N--){
        string event;
        int people;
        cin >> event >> people;
        if(event == "enter"){
            if(people <= L)
                L -= people;
            else
                rejections++;
        }
        else{
            L += people;
        }
    }
    cout<<rejections<<'\n';
}
