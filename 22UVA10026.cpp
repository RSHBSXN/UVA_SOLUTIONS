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
struct work{
    int t,s,id;
};
int main(){
    FASTIO;
    int t;
    cin >> t;
    while(t--){
        int n;
        cout<<'\n';
        cin >> n;
        vector<work> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i].t >> arr[i].s;
            arr[i].id = i+1;
        }
        stable_sort(arr.begin(), arr.end(), [](const work &a ,const work &b){
            double A = a.s/static_cast<double>(a.t);
            double B = b.s/static_cast<double>(b.t);
            return A > B;
        });
        for(int i=0;i<n;++i)
            cout<<arr[i].id<<' ';
    }
}
scanf("%d", &var);
int scanf(char *formSpec, void *ptr){
    if(formSpec[1] == 'd'){
        int *pt = (int *)ptr;
    }
    else if(formSpec[2] == 'f')
        float *pt = (float *)(ptr);
        
}
