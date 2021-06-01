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
    int n;
    cin >> n;
    int totalAllowed = 0;
    while(n--){
        int allowed = 0;
        double l,w,d,mass;
        cin >> l >> w >> d >> mass;
        if((l + w + d <= 125.00 || (l <= 56.00 && w <= 45.00 && d <= 25.00)) && mass <= 7.00)
            allowed = 1;
        cout<<allowed<<'\n';
        totalAllowed += allowed;
   }
   cout<<totalAllowed<<'\n';
}
