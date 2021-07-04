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
    vector<string> notes = {
        "C",
        "C#",
        "D",
        "D#",
        "E",
        "F",
        "F#",
        "G",
        "G#", 
        "A",
        "A#",
        "B"
    };
    vector<int> move = {2, 2, 1, 2, 2, 2 ,1};
    string line;
    while(getline(cin, line) && line != "END"){
        stringstream sin(line);
        bool first = true;
        set<string> givNotes;
        string nt;
        while(sin >> nt)
            givNotes.insert(nt);
        int pos = 0;
        for(string &key : notes){
            bitset<12> invalid;
            int mv = pos;
            pos++;
            for(int i=0;i<move.size();++i){
                
                mv = (mv + move[i]) % 12;
                invalid[mv] = 1;
            }
            bool valid = true;
            for(int i = 0; i < 12;++i){
                if(!invalid[i] && givNotes.find(notes[i]) != givNotes.end()){
                    valid = false;
                    break;
                }
            }
            if(valid){
                if(first)
                    first = false;
                else
                    cout<<' ';
                cout<<key;
            }
        }
        cout<<'\n';
    }
}
