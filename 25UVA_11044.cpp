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
int main(){
    int t;
    cin >> t;
    while(t--){
        int N,M;
        cin >> N >> M;
        N -= 2;
        M -= 2;
        int n,m;
        n = N / 3;
        m = M / 3;
        if(N % 3 != 0)
            n++;
        if(M % 3 != 0)
            m++;
        cout<<n * m<<'\n';
    }
}
