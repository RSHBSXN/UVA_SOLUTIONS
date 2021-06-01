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
    int r,c;
    while(cin >> r >> c && (r != 0 || c != 0)){
        int r1 = r, c1 = c;
        if(r1 > c1)
            swap(r1,c1);
        if(r1 == 1)
            cout<<c1;
        else if(r1 == 2){
            int knights = (c1 / 4) * 2;
            int mod = c1 % 4;
            if(mod != 0){
                if(mod == 1)
                    knights++;
                else if(mod == 2 || mod == 3)
                    knights += 2;
            }
            knights <<= 1;
            cout<<knights;
        }
        else{
            int knights = 0;
            int x = r1 >> 1;
            int y = c1 >> 1;
            knights = x * y;
            if((r1 & 1) && (c1 & 1)){
                knights += ((x + 1) * (y + 1)); 
            }
            else if(r1 & 1){
                knights += ((x + 1) * y);
            }
            else if(c1 & 1){
                knights += (x * (y + 1));
            }
            else{
                knights += x * y;
            }
            cout<<knights;
        }
        cout<<" knights may be placed on a "<<r <<" row "<<c<<" column board.\n";
    }
    
}
/*
    2,10 =>KK..KK..K
           KK..KK..K
           
    
    4,6 => K    .   K   .   K   .
           .    K   .   K   .   K
           K    .   K   .   K   .
           .    K   .   K   .   K
*/

