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
    int n,d,r;
    while(cin >> n >> d >> r && n != 0 && d != 0 && r != 0){
        vi A(n),B(n);
        for(int &i : A)
            cin >> i;

        for(int &i : B)
            cin >> i;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end(),[](int &a, int &b){
            return a > b;
        });
        int total = 0;
        for(int i=0;i<n;++i){
            int dist = A[i] + B[i];
            if(dist > d)
                total += (dist - d) * r;
        }
        cout<<total<<'\n';
    }
}
