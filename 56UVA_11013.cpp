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
vector<char> face = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
unordered_map<char, int> Rank = {{'A', 1}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}};
unordered_map<char,int> cardCount;
bool hasRunX(vector<int> &freq, int X){
    int cont = 0;
    int maxCont = 0;
    for(int i=1;i<14;++i){
        bool found = true;
        int count = 0;
        for(int j=i;found && count < X;count++){
            
            found = found && freq[j];
            j++;
            if(j >= 14)
                j = j % 14 + 1;
        }
        if(found)
            return true;
    }
    return false;
}
bool hasRun32(vector<int> &freq){
    bool run3 = false, run2 = false;
    int ind;
    for(int i=1;i<=13;++i){
        int second = i + 1;
        int third = i + 2;
        if(second >= 14)
            second = second % 14 + 1;
        if(third >= 14)
            third = third % 14 + 1;
        if(freq[i] && freq[second] && freq[third]){
            run3 = true;
            ind = i;
            freq[i]--;
            freq[second]--;
            freq[third]--;
            break;    
        }
    }
    for(int i=1;i<=13;++i){
        int second = i + 1;
        if(second >= 14)
            second = second % 14 + 1;
        if(freq[i] && freq[second]){
            run2 = true;
            break;
        }
    }
    for(int i=ind, count = 3;run3 && count;--count){//3210
        freq[i]++;
        i++;
        if(i >= 14)
            i = i % 14 + 1;
    }
    return run3 && run2;
}
bool hasRun22(vector<int> &freq){
    int ind = 0;
    int run2 = 0;
    for(int i=1;i<=13;++i){
        int second = i + 1;
        if(second >= 14)
            second = second % 14 + 1;
        if(freq[i] && freq[second]){
            ind = i;
            freq[i]--;
            freq[second]--;
            run2++;
            break;
        }
    }
    for(int i=1;i<=13;++i){
        int second = i + 1;
        if(second >= 14)
            second = second % 14 + 1;
        if(freq[i] && freq[second]){
            run2++;
        }
    }
    if(ind){
        freq[ind]++;
        int second = ind + 1;
        if(second >= 14)
            second = second % 14 + 1;
        freq[second]++;
    }
    return run2 == 2;
}
pair<double,int> repCard(vector<string> &cards, vector<int> &freq){
    for(char &x : face)
        cardCount[x] = 4;
    for(int i=0;i<5;++i){
        cardCount[cards[i][0]]--;
    }
    double maxE = DBL_MIN_EXP;
    int card = 0;

    for(int i=0;i<5;++i){
        freq[Rank[cards[i][0]]]--;
        
        double e = 0;
        int run5, run4, run32, run3, run22;
        run5 = run4 = run32 = run3 = run22 = 0;
        for(char &f : face){
            freq[Rank[f]]++;
            if(hasRunX(freq, 5))
                run5 += cardCount[f];
            else if(hasRunX(freq, 4))
                run4 += cardCount[f];
            else if(hasRun32(freq))
                run32 += cardCount[f];
            else if(hasRunX(freq, 3))
                run3 += cardCount[f];
            else if(hasRun22(freq))
                run22 += cardCount[f];
            freq[Rank[f]]--;
        }
        e = (((run5/47.00) * 100) + ((run4/47.00) * 10) + ((run32/47.00) * 5) + ((run3/47.00) * 3) + (run22/47.00)) - 2.0000000000;
        if(e > maxE){
            maxE = e;
            card = i;
        }
        freq[Rank[cards[i][0]]]++;
    }
    return {maxE, card};
}
int main(){
    FASTIO;
    for(int i=2;i<=9;++i){
        Rank[i + '0'] = i;
    }
    string cardStr;
    while(getline(cin, cardStr) && cardStr != "#"){
        vector<int> freq(14);
        vector<string> cards;
        string card;
        stringstream cardIn(cardStr);
        while(cardIn >> card){
            cards.push_back(card);
            freq[Rank[card[0]]]++;
        }
        if(hasRunX(freq, 5))
            cout<<"Stay";
        else{
            double val = -1.0000;
            if(hasRunX(freq, 4))
                val = 9;
            else if(hasRun32(freq))
                val = 4;
            else if(hasRunX(freq, 3))
                val = 2;
            else if(hasRun22(freq))
                val = 0;
            pair<double, int> res = repCard(cards, freq);
            if(res.first > val)
                cout<<"Exchange "<<cards[res.second];
            else
                cout<<"Stay";
        }
        cout<<'\n';
    }
}
