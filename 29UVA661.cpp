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
    int n,m,fuse;
    int seq = 1;
    while(cin >> n >> m >> fuse && (n != 0 || m != 0 || fuse != 0)){
        vector<int> c(n);
        vector<bool> st(n);
        for(int &i : c)
            cin >> i;
        int totalC = 0;
        int maxC = 0;
        while(m--){
            int sw;
            cin >> sw;
            sw--;
            if(!st[sw])
                totalC += c[sw];
            else
                totalC -= c[sw];
            st[sw] = !st[sw];
            maxC = max(maxC, totalC);
        }
        cout<<"Sequence "<<seq++<<'\n';
        if(maxC <= fuse){
            cout<<"Fuse was not blown."<<'\n';
            cout<<"Maximal power consumption was "<<maxC<<" amperes.";
        }
        else
            cout<<"Fuse was blown.";
        cout<<"\n\n";
    }
}
