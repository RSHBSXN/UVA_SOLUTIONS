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
struct interval{
    int L,R;
};
int main(){
    int L,G;
    while(cin >> L >> G && L != 0 && G != 0){
        vector<interval> arr(G);
        for(interval &i : arr){
            int m,d;
            cin >> m >> d;
            i.L = m - d;
            i.R = m + d;
        }
        sort(arr.begin(),arr.end(),[](interval &a, interval &b){
            return a.L <= b.L || (a.L == b.L && a.R > b.R);
        });
        int i=0,total = 0,coverRight = 0;
        while(i < G && coverRight < L){
            int auxR = coverRight;
            bool valid = false;
            while(i < G && arr[i].L <= coverRight){
                valid = true; 
                auxR = max(auxR,arr[i++].R); 
            }
            if(!valid || auxR == coverRight){
                total = -1;
                break;
            }
            else{
                total++;
                coverRight = auxR;
            }
        }
        if(total == -1 || coverRight < L)
            cout<<-1;
        else
            cout<<G - total;
        cout<<'\n';
    }
}
