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
unsigned ll toNum(string str){
    unsigned ll num = 0;
    for(int i = str.size() -1 ; i>=0;--i){
        if(str[i] == '1')
            num += ((unsigned ll)1 << (str.size() - 1 - i));
    }
    return num;
}
int main(){
    int b,v;
    while(cin >> b >> v){
        unordered_map<string, pair<int, unsigned ll>> vars;
        vector<string> order;
        while(v--){
            string name;
            cin >> name;
            cin >> vars[name].first;
            order.push_back(name);
        }
        for(string &str : order){
            string binNum;
            for(int i=0;i<vars[str].first;++i){
                string word;
                cin >> word;
                binNum += word;
            }
            vars[str].second = toNum(binNum);
        }
        int q;
        cin >> q;
        while(q--){
            string num;
            cin >> num;
            cout<<num<<'=';
            if(vars.find(num) != vars.end())
                cout<<vars[num].second;
            cout<<'\n';
        }
    }
}
