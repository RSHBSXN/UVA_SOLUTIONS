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
int getRound(int a, int b, int left, int right){
    int mid = (left + right) >> 1;
    if(a >= left && a <= mid && b > mid && b <= right)
        return 0;
    else if(max(a,b) <= mid){
        return 1 + getRound(a, b, left, mid);
    }
    else
        return 1 + getRound(a, b, mid + 1, right);
}
int main(){
    int N,a,b;
    while(cin >> N >> a >> b){
        cout<<N - getRound(min(a,b),max(a,b),1, (1 << N))<<'\n';
    } 
}
