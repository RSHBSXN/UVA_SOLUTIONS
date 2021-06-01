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
    int N;
    char B;
    cin >> N >> B;
    N *= 4;
    int score = 0;
    while(N--){
        
        string card;
        cin >> card;
        if(card[1] == B && (card[0] == 'J' || card[0] == '9')){
            if(card[0] == 'J')
                score += 20;
            else
                score += 14;
        }
        else{
            switch(card[0]){
                case 'A':
                    score += 11;
                    break;
                case 'K':
                    score += 4;
                    break;
                case 'Q':
                    score += 3;
                    break;
                case 'J':
                    score += 2;
                    break;
                case 'T':
                    score += 10;
            }
        }
    }
    cout<<score<<'\n';
}
