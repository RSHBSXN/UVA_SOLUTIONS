#if __APPLE__
    #include <iostream>
    #include <vector>
    #include <map>
    #include <set>
    #include <string>
    #include <cstring>
    #include <algorithm>
    #include <sstream>

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
    string line;
    map<char, int> suit = {{'S', 0}, {'H', 1}, {'D', 2}, {'C', 3}};
    map<char, int> rank = {{'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};
    for(char i = '2';i<='9';++i)
        rank[i] = i - '0';

    while(getline(cin, line)){
        stringstream buff(line);
        string card;
        vector<string> cards;
        //C = 0, D = 1, H = 2, S = 3
        int points = 0;
        vector<int> countSuit(4);
        vector<int> countRank(15);
        vector<bool> subRank(15);
        vector<bool> isStopped(4);
        while(buff >> card){
            cards.push_back(card);
            countSuit[suit[card[1]]]++;
            countRank[rank[card[0]]]++;
        }
        int points_by_567 = 0;
        // Add points for rank
        for(int i=11;i<15;++i) {
            points += (i - 10) * countRank[i];
        }

        // Add points for suit
        for(int i=0;i<4;++i){
            if(countSuit[i] <= 1)
                points_by_567 += 2;
            else if(countSuit[i] == 2)
                points_by_567++;
        }
        for(string &c : cards){
            // Subtract points for rank
            switch(rank[c[0]]){
                case 11:
                    (countSuit[suit[c[1]]] <= 3 && !subRank[rank[c[0]]]) && (points--) && (subRank[rank[c[0]]] = !subRank[rank[c[0]]]);
                    break;
                case 12:
                    (countSuit[suit[c[1]]] <= 2 && !subRank[rank[c[0]]]) && (points--) && (subRank[rank[c[0]]] = !subRank[rank[c[0]]]);
                    break;
                case 13:
                    (countSuit[suit[c[1]]] == 1 && !subRank[rank[c[0]]]) && (points--) && (subRank[rank[c[0]]] = !subRank[rank[c[0]]]);
                    break;
            }
            switch (rank[c[0]]){
                case 12:
                    countSuit[suit[c[1]]] >= 3 && (isStopped[suit[c[1]]] = true);
                    break;
                case 13:
                    countSuit[suit[c[1]]] >= 2 && (isStopped[suit[c[1]]] = true);
                    break;
                case 14:
                    isStopped[suit[c[1]]] = true;
                    break;
            }
        }
        if(points + points_by_567 < 14)
            cout<<"PASS";
        else{
            if(points >= 16){
                bool trump = true;
                for(int i=0;i<isStopped.size() && trump;++i){
                    if(!isStopped[i])
                        trump = false;
                }
                if(trump) {
                    cout << "BID NO-TRUMP\n";
                    continue;
                }
            }
            int maxSuit = 0;
            for(int i=1;i<4;++i){
                if(countSuit[i] > countSuit[maxSuit])
                    maxSuit = i;
            }
            cout<<"BID ";
            switch (maxSuit) {
                case 0:
                    cout<< "S";
                    break;
                case 1:
                    cout<< "H";
                    break;
                case 2:
                    cout<< "D";
                    break;
                case 3:
                    cout<< "C";
            }
        }
        cout<<'\n';
        buff.clear();
    }
}
