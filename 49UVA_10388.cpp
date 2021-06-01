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
    int n;
    cin >> n;
    bool first = true;
    while(n--){
        if(!first){
            cout<<'\n';
        }
        first =false;
        string jane, john, faceUpJane, faceUpJohn;
        cin >> jane >> john;
        int turns = 1;
        int janeInd = 0, johnInd = 0;
        string result = "Keeps going and going ...";
        while(turns <= 1000){
            if(janeInd >= jane.size()){
                jane = faceUpJane;
                faceUpJane.clear();
                janeInd = 0;
            }
            if(johnInd >= john.size()){
                john = faceUpJohn;
                faceUpJohn.clear();
                johnInd = 0;
            }

            if(jane.empty() && faceUpJane.empty()){
                result = "John wins.";
                break;
            }
            else if(john.empty() && faceUpJohn.empty()){
                result = "Jane wins.";
                break;
            }

            faceUpJane.push_back(jane[janeInd]);
            faceUpJohn.push_back(john[johnInd]);
            
            if(jane[janeInd] == john[johnInd]){
                bool isJohn = random()/141%2;
                cout<<"Snap! for ";
                if(isJohn){
                    faceUpJohn += faceUpJane;
                    faceUpJane.clear();
                    cout<<"John: ";
                    for(int i=faceUpJohn.size()-1;i>=0;--i)
                        cout<<faceUpJohn[i];
                }
                else{
                    faceUpJane += faceUpJohn;
                    faceUpJohn.clear();
                    cout<<"Jane: ";
                    for(int i=faceUpJane.size()-1;i>=0;--i)
                        cout<<faceUpJane[i];
                }
                cout<<'\n';
            }
            janeInd++;
            johnInd++;
            turns++;
        }
        cout<<result<<"\n";
    }
}
