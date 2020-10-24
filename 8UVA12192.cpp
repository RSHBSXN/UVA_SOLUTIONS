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
#define vll vector<ll>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PREC 1e-9
int main(){
    FASTIO;
    int n,m;
    while(cin >> n >> m && n != 0 && m != 0){
        MATRIX MAT(n,vi(m));
        for(vi &arr : MAT)
            for(int &i : arr)
                cin >> i;
        int t;
        cin >> t;
        while(t--){
            int l,r;
            cin >> l >> r;
            int maxSize = 0;
            for(int i=0;i<n;++i){
                int pos = lower_bound(MAT[i].begin(),MAT[i].end(),l) - MAT[i].begin();
                for(int j=0;i+j < n && pos + j < m;++j){
                    if(MAT[i+j][pos+j] <= r)
                        maxSize = max(maxSize,j+1); 
                    else
                        break;   
                }
            }
            cout<<maxSize<<'\n';
        }
        cout<<"-\n";
    }
}
