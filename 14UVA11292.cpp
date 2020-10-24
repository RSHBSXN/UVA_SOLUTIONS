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
vi dragon,knight;
int binarySearch(int &left,int right,int diam){
    int L = left,R = right;
    while(R - L > 1){
        int mid = (L + R) >> 1;
        if(knight[mid] >= diam)
            R = mid;
        else
            L = mid + 1;
    }
    if(knight[L] >= diam){
        left = L;
        left++;
        return L;
    }
    else if(knight[R] >= diam){
        left = R;
        left++;
        return R;
    }
    else
        return -1;
}
int main(){
    int n,m;
    while(cin >> n >> m && n != 0 && m != 0){
        dragon = vi(n),knight = vi(m);
        for(int &i : dragon)
            cin >> i;
        for(int &i : knight)
            cin >> i;
        sort(dragon.begin(),dragon.end());
        sort(knight.begin(),knight.end());
        int left = 0,right = m-1;
        bool valid = true;
        int coins = 0;
        for(int i=0;i<n && valid;++i){
            int knightIn = binarySearch(left,right,dragon[i]);
            if(knightIn == -1 || (left == knight.size() && i < n-1))
                valid = false;
            else{
                coins += knight[knightIn];
            }
        }
        cout<<((valid)?to_string(coins):"Loowater is doomed!")<<'\n';
    }
}
