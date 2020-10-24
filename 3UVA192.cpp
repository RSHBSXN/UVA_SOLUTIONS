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
    
    int K;
    cin >> K;
    while(K != 0){
        int N,M;
        cin >> N >> M;
        while(K--){
            int a,b;
            cin >> a >> b;
            if(a == N || b == M)
                cout<<"divisa";
            else if(a < N){
                if(b > M)
                    cout<<"NO";
                else
                    cout<<"SO";
            }
            else{
                if(b > M)
                    cout<<"NE";
                else
                    cout<<"SE";
            }
            cout<<'\n';
        }
        cin >> K;
    }
}
