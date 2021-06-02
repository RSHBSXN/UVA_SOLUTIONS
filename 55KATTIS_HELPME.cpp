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
    string line;
    int row = 8;
    map<char, int> toInd = {{'K', 0}, {'Q', 1}, {'R', 3}, {'B', 4}, {'N', 5}, {'P', 6}};
    vector<vector<string>> blacks(7), whites(7);
    int countW = 0, countB = 0;
    while(getline(cin, line)){
        char col = 'a';
        getline(cin, line);
        if(line.empty())
            break;
        stringstream sbuff(line);
        sbuff.seekg(1);
        string piece;
        for(;getline(sbuff, piece, '|'); col++){
            if(piece == ":::" || piece == "...")
                continue;
            else{
                stringstream str;
                if(piece[1] != 'p' && piece[1] != 'P'){
                    str << (char)toupper(piece[1]);
                }
                str << col << row;
                if(islower(piece[1])){
                    blacks[toInd[(char)toupper(piece[1])]].push_back(str.str());
                    countB++;
                }
                else{
                    whites[toInd[(char)toupper(piece[1])]].push_back(str.str());
                    countW++;
                }
            }
        }
        row--;
    }
    for(int i=0;i<7;++i){
        sort(whites[i].begin(), whites[i].end(), [](string &a, string &b){
            int aLen = a.length(), bLen = b.length();
            int aRow = a.back();
            char aCol = *(a.rbegin() - 1);
            int bRow = b.back();
            char bCol = *(b.rbegin() - 1);
            return aRow < bRow || (aRow == bRow && aCol < bCol); 
        });
    }
    for(int i=0;i<7;++i){
        sort(blacks[i].begin(), blacks[i].end(), [](string &a, string &b){
            int aLen = a.length(), bLen = b.length();
            int aRow = a.back();
            char aCol = *(a.rbegin() - 1);
            int bRow = b.back();
            char bCol = *(b.rbegin() - 1);
            return aRow > bRow || (aRow == bRow && aCol < bCol); 
        });
    }
    cout<<"White: ";
    for(vector<string> &v : whites){
        for(string &s : v){
            cout<<s;
            if(--countW)
                cout<<',';
        }
    }
    cout<<"\nBlack: ";
    for(vector<string> &v : blacks){
        for(string &s : v){
            cout<<s;
            if(--countB)
                cout<<',';
        }

    }
}
