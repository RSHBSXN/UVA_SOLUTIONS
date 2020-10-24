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
    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        int totalCount = 52;
        vector<string> deck, hand;
        string card;
        while(totalCount > 25){
            cin >> card;
            deck.push_back(card);
            totalCount--;
        }
        while(totalCount--){
            cin >> card;
            hand.push_back(card);
        }
//        reverse(hand.begin(), hand.end());
        int Y = 0;
        for(int i=0;i<3;++i){
            card = deck.back();
            deck.pop_back();
            int X = 10;
            if(card[0] >= '0' && card[0] <= '9')
                X = card[0] - '0';
            Y += X;
            for(int j=1;j <= 10 - X;++j)
                deck.pop_back();
        }

        Y--;
        string res;
        if(Y < deck.size())
            res = deck[Y];
        else{
            Y -= deck.size();
            res = hand[Y];
        }
        cout<<"Case "<<t<<": "<<res<<'\n';
    }
}
