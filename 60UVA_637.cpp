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
    int pages;
    while(cin >> pages && pages){
        int st = 1, end = pages + ((pages % 4) ? (4 - pages % 4) : 0);
        cout<<"Printing order for "<<pages<<" pages:\n";
        bool onFront = true;
        for(int sheet = 1;st < end;++st, --end){
            if(st <= pages || end <= pages){
                int tp = end, btm = st;
                string res = "Sheet " + to_string(sheet) + ", ";
                res += (onFront) ? "front: ":"back : ";
                if(!onFront)
                    swap(tp, btm);
                onFront = !onFront;
                if(onFront)
                    sheet++;
                res += ((tp <= pages) ? to_string(tp) : "Blank") + ", " ;
                res += ((btm <= pages) ? to_string(btm) : "Blank");
                cout<<res<<'\n';
            }
            else
                break;
        } 
    }
}
