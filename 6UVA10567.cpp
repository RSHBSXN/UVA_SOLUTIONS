#if __APPLE__
    #include <iostream>
    #include <vector>
    #include <map>
    #include <set>
    #include <string>
    #include <algorithm>
    #include <unordered_map>
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
int binarySearch(vi &arr,int index){
    int l = 0,r = arr.size()-1;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(arr[mid] > index)
            r = mid;
        else
            l = mid + 1;
    }
    if(arr[l] > index)
        return l;
    else if(arr[r] > index)
        return r;
    else
        return -1;
}
int main(){
    string S;
    cin >> S;
    unordered_map<char,vi> CharPos;
    for(int i=0;i<S.length();++i){
        CharPos[S[i]].push_back(i);
    }
    int Q;
    cin >> Q;
    while(Q--){
        int start = -1,index = -1;
        string t;
        cin >> t;
        for(int i=0;i<t.size();++i){
            int ind = binarySearch(CharPos[t[i]],index);
            if(ind == -1){
                index = -1;
                break;
            }
            index = CharPos[t[i]][ind];
            if(start == -1)
                start = index;
        }
        if(index == -1)
            cout<<"Not matched";
        else
            cout<<"Matched "<<start<<" "<<index;
        cout<<'\n';
    }
    
}
