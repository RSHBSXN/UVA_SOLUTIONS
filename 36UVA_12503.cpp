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
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        v(int) inst(n);
        int curr = 0;
        cin.ignore();
        for(int &i : inst){
            string str;
            getline(cin, str);
            if(str == "LEFT")
                i = -1;
            else if(str == "RIGHT")
                i = 1;
            else{
                i = inst[stoi(str.substr(7)) - 1];
            }
            curr += i;
        }
        cout<<curr<<'\n';
    }
}
