#if __APPLE__
    #include <iostream>
    #include <iomanip>
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
    string str;
    map<char,int> MAP = {{'J', 1}, {'Q', 2}, {'K', 3}, {'A', 4}};
    vector<string> res;
    while(true){
        vector<int> player, dealer;
        bool pickPlayer = true;
        for(int i=1;i<=4;++i){
            getline(cin, str);
            if(str == "#")
                break;
            for(int j=1;j<str.length();j += 3){
                if(pickPlayer)
                    (j & 1)? player.push_back(MAP[str[j]]) : dealer.push_back(MAP[str[j]]);
                else
                    (j & 1)? dealer.push_back(MAP[str[j]]) : player.push_back(MAP[str[j]]);
            }
            pickPlayer = !pickPlayer;
        }
        if(str == "#")
            break;
        vector<int> deck;
        vector<int> *draw = &player, *other = &dealer;
        while(true){
            if(draw->empty())
                break;
            int card = draw->back();
            draw->pop_back();
            deck.push_back(card);
            if(card != 0){
                bool take = false;
                for(int i=1;i<=card && !other->empty();++i){
                    int otherCard = other->back();
                    if(otherCard != 0)
                        break;
                    else{
                        deck.push_back(otherCard);
                        other->pop_back();
                        if(i == card)
                            take = true;
                    }
                }
                if(take){
                    reverse(deck.begin(), deck.end());
                    for(int i : *draw)
                        deck.push_back(i);
                    *draw = deck;
                    deck = vector<int>();
                    swap(draw, other);
                }
            }
            swap(draw, other);
        }
        if(!player.empty())
            cout<<2<<setw(3)<<player.size();
        else
            cout<<1<<setw(3)<<dealer.size();
        cout<<'\n';
    }
}
