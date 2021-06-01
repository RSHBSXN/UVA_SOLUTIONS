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
    unsigned int N, t;
    cin >> N >> t;
    v(int) ARR(N);
    unsigned ll sum = 0;
    string res;
    for(int &x : ARR)
        cin >> x;
    switch(t){
        case 1:
            cout<<7;
            break;
        case 2:
            if(ARR[0] > ARR[1])
                res = "Bigger";
            else if(ARR[0] == ARR[1])
                res = "Equal";
            else
                res = "Smaller";
            cout<<res;
            break;
        case 3:
            for(int i=0;i<3;++i){
                if((ARR[i] <= ARR[(i+1) % 3] && ARR[i] >= ARR[(i+2) % 3]) ||  (ARR[i] >= ARR[(i+1) % 3] && ARR[i] <= ARR[(i+2) % 3])){
                    cout<<ARR[i];
                    break;
                }
            }
            break;
        case 4:
            for(int i : ARR)
                sum += i;
            cout<<sum;
            break;
        case 5:
            for(int i : ARR){
                if(!(i & 1))
                    sum += i;
            }
            cout<<sum;
            break;
        case 6:
            for(int &i : ARR){
                i %= 26;
                cout<<(char)('a' + i);
            }
            break;
        case 7:
            set<int> visInd = {0};
            for(int i=ARR[0];true; i = ARR[i]){
                if(visInd.find(i) != visInd.end()){
                    cout<<"Cyclic";
                    break;
                }
                else if(i > N-1){
                    cout<<"Out";
                    break;
                }
                else if(i == N-1){
                    cout<<"Done";
                    break;
                }
                visInd.insert(i);
            }
            break;
    }
}
