/*
    Author: Rishabh Saxena
    All the best!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define xll __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define v(x) vector<x>
#define MATRIX(x) vector<vector<x>>
#define MATRIX3D(x) vector<vector<vector<x>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PREC 1e-9
int main(){
    int t;
    cin >> t;
    unordered_map<char, double> mass = {{'C', 12.01}, {'H', 1.008}, {'O', 16.00}, {'N', 14.01}};
    while(t--){
        string comp;
        cin >> comp;
        double atomic_mass = 0.0;
        int mult = 0;
        char element = -1;
        for(int i=0;i<comp.size();++i){
            if(comp[i] >= 'A' && comp[i] <= 'Z'){
                if(element != -1){
                    if(mult > 0)
                        atomic_mass += mass[element] * mult;
                    else
                        atomic_mass += mass[element];
                    
                }
                element = comp[i];
                mult = 0;
            }
            else
                mult = (mult * 10) + (comp[i] - '0');  
        }
        if(mult > 0)
            atomic_mass += mass[element] * mult;
        else
            atomic_mass += mass[element];
        cout<<fixed<<setprecision(3)<<atomic_mass<<'\n';
    }
    
}
