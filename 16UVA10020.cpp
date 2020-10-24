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
#define vll vector<ll>
#define vi vector<int>
#define MATRIX vector<vector<int>>
#define MATRIXB vector<vector<bool>>
#define MATRIXC vector<vector<char>>
#define MATRIXLL vector<vector<ll>>
#define MATRIX3D vector<vector<vector<int>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PREC 1e-9
class Range{
    public:
        int L,R;
        Range(){}
        Range(int A,int B){
            L = A;
            R = B;
        }
};
int main(){
    int t;
    cin >> t;
    while(t--){
        int M;
        cin >> M;
        int L,R;
        vector<Range> arr;
        vi resInd;
        while(cin >> L >> R && (L != 0 || R != 0)){
            arr.push_back(*(new Range(L,R)));
        }
        sort(arr.begin(), arr.end(),[](Range &a, Range &b){
            return a.L < b.L || (a.L == b.L && a.R > b.R);
        });
        int covR = 0;
        bool valid = true;
        for(int i=0;i<arr.size();++i){
            int j,maxC = -1;
            bool exist = false;
            for(j = i;j < arr.size() && arr[j].L <= covR;++j){
                if(maxC == -1 || arr[j].R > arr[maxC].R)
                    maxC = j;
                if(arr[maxC].R > covR)
                    exist = true;
            }
            if(!exist){
                valid = false;
                break;
            }
            else{
                resInd.push_back(maxC);
                covR = arr[maxC].R;
                if(covR >= M)
                    break;
            }
        }
        if(valid){
            cout<<resInd.size()<<'\n';
            for(int i : resInd)
                cout<<arr[i].L<<' '<<arr[i].R<<'\n';
        }
        else
            cout<<0;
        cout<<"\n\n";
    }
}
