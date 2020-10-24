#if __APPLE__
    #include <iostream>
    #include <vector>
    #include <map>
    #include <set>
    #include <string>
    #include <algorithm>
    #include <cmath>
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
struct interval{
    long double left,right;
};
int main(){
    int N,L,W;
    while(cin >> N >> L >> W){
        bool possible = true;
        int sprnk = 1;
        vector<interval> arr;
        for(int i=0;i<N;++i){
            long double point,rad;
            cin >> point >> rad;
            if(rad * 2 >= W){
                double dx = sqrt(rad * rad - (W * W)/4.0);          
                arr.push_back({point - dx, point + dx});
            }
        }
        sort(arr.begin(), arr.end(),[](interval &a,interval &b){
            return a.left < b.left || (a.left == b.left && a.right > b.right);
        });
        if(arr.size() == 0 || arr[0].left > 0)
            possible = false;
        else{
            interval curr = arr[0];
            interval Max = {INT32_MIN,INT32_MIN};
            for(int i=1;i<arr.size() && curr.right < L;++i){
                if(arr[i].left > curr.right && arr[i].left > Max.right){
                   possible = false;
                   break; 
                }
                else if(arr[i].left <= curr.right && arr[i].right >= Max.right){
                    if(arr[i].left < 0)
                        curr = arr[i];
                    else
                        Max = arr[i];
                }
                else if(arr[i].left > curr.right){
                    curr = Max;
                    sprnk++;
                    if(arr[i].right > curr.right)
                        Max = arr[i];
                    else
                        Max = {-1,-1};
                }
            }
            if(max(Max.right, curr.right) < L)
                possible = false;
            else if(Max.right >= L && curr.right < L)
                sprnk++;
            
        }
        cout<<((possible)?sprnk:-1)<<'\n';
    }
}
