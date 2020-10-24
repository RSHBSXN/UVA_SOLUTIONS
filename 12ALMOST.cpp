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
//  1   2   5   3   5
//  1   2   1   2   1
bool almostInc(vi &arr){
    int lastInc = -1;
    int depCount = 0,depIn;
    for(int i=0;i<arr.size()-1;++i){
        if(lastInc != -1 && lastInc < arr[i+1]){
            lastInc = arr[i+1];
        }
        else if(lastInc == -1 && arr[i] < arr[i+1]){
            lastInc = arr[i+1];
        }
        else{
            depCount++;
            depIn = i;
        }
    }
    if(depCount == 1){
        if(depIn > 0 && arr[depIn - 1] < arr[depIn + 1])
            
    }
    return depCount <= 1;
}
int main(){
    int n;
    cin >> n;
    vi arr(n);
    for(int &i : arr)
        cin >> i;
    cout<<almostInc(arr)<<'\n';
}
