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
    while(t--){
        int n;
        cin >> n;
        vi arr(n);
        for(int &i : arr)   
            cin >> i;
        int coins = 1;
        int sum = arr[0];
        for(int i=1;i<n;++i){
            if(i == n-1)
                coins++;
            else if(sum + arr[i] < arr[i+1]){
                sum += arr[i];
                coins++;
            }
        }
        cout<<coins<<'\n';
    }
}
