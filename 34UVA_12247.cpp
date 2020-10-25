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
    int A,B,C,D,E;
    while(cin >> A >> B >> C >> D >> E && A != 0){
        v(bool) deck(53, true);
        deck[A] = false;
        deck[B] = false;
        deck[C] = false;
        deck[D] = false;
        deck[E] = false;
        int max,max2;
        if(A < B && A < C){
            if(B > C)
                max = B, max2 = C;
            else
                max = C, max2 = B;
        }
        else if(B < C && B < A){
            if(A > C)
                max = A, max2 = C;
            else
                max = C, max2 = A;
        }
        else
            if(A > B)
                max = A, max2 = B;
            else
                max = B, max2 = A;

        if(D > E)
            swap(D,E);
        if(E < max && D < max2)
            cout<<-1;
        else{
            int F;
            if(D < max2)
                F = max;
            else if(D < max)
                F = max2;
            else
                F = 0;
            for(F += 1;F<53 && !deck[F];++F);
            cout<<((F != 53)?F:-1);
        }
        cout<<'\n';
    }

}
