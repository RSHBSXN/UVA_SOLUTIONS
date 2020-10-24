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
    double H,D;
    double F,U;
    while(cin >> H >> U >> D >> F && H != 0){
        F /= 100;
        F = U * F;
        double dist = 0;
        int day = 0;
        
        while(dist < H && dist >= 0){
            if(U > 0)
                dist += U;
            day++;
            if(dist > H)
                break;
            dist -= D;
            U = U - F;
        }
        cout<<((dist < H) ? "failure":"success")<<" on day "<<day<<'\n';
    }
}
