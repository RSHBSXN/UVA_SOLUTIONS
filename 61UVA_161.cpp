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
    while(true){
        int num;
        cin >> num;
        if(num == 0)
            break;
        v(int) times(1, num);
        while(cin >> num && num != 0)
            times.push_back(num);
        sort(times.begin(), times.end());
        int sec = -1;
        for(int second = times.front() * 2; second <= 18000; second++){
            bool valid = true;
            for(int &intr : times){
                int mult = second / intr;
                if(mult & 1){
                    valid = false;
                    break;
                }
                else{
                    int UL = intr * (mult + 1);
                    if(second >= UL - 5){
                        valid = false;
                        break;
                    }
                }
            }
            if(valid){
                sec = second;
                break;
            }
        }
        
        if(sec == -1)
            printf("Signals fail to synchronise in 5 hours\n");
        else{
            int seconds = sec % 60;
            int mins = sec / 60;
            int hrs = mins / 60;
            mins = mins % 60;
            printf("%02d:%02d:%02d\n", hrs, mins, seconds);
        }
    }
}
