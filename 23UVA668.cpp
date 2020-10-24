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
    int t;
    cin >> t;
    cout<<'\n';
    while(t--){
        int N;
        cin >> N;
        cout<<'\n';
        vi arr;
        for(int i = 2;i<=N;++i){
            arr.push_back(i);
            N -= i;
        }
        for(int i=arr.size()-1;i>=0 && N > 0;--i){
            arr[i]++;
            N--;
        }
        if(N > 0)
            arr[arr.size()-1] += N;
        for(int i : arr)
            cout<<i<<' ';
        cout<<'\n';
    }
}
