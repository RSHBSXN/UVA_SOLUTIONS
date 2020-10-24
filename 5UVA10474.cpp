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
int binarySearch(vi &arr, int number){
    int L = 0,R = arr.size()-1;
    while(R - L > 1){
        int mid = (L + R) >> 1;
        if(arr[mid] >= number)
            R = mid;
        else{
            L = mid + 1;
        }
    }
    if(arr[L] == number)
        return L+1;
    else if(arr[R] == number)
        return R+1;
    else
        return -1;
}
int main(){
    int N,Q;
    int t = 1;
    while(cin >> N >> Q && N != 0 && Q != 0){
        vi arr(N);
        for(int &i : arr)
            cin >> i;
        sort(arr.begin(), arr.end());
        cout<<"CASE# "<<t++<<":\n";
        while(Q--){
            int number;
            cin >> number;
            int pos = binarySearch(arr, number);
            if(pos != -1)
                cout<<number<<" found at "<<pos;
            else
                cout<<number<<" not found";
            cout<<'\n';
        }
    }
}
