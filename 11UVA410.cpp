#if __APPLE__
    #include <iostream>
    #include <vector>
    #include <map>
    #include <set>
    #include <string>
    #include <algorithm>
    #include <iomanip>
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
MATRIX OUTPUT;
int main(){
    int C,S;
    int t = 1;
    while(cin >> C >> S){
        vi arr(S);
        double imb = 0,avg = 0;
        OUTPUT = MATRIX(C);
        for(int &i : arr){
            cin >> i;
            avg += i;
        }
        avg /= C;
        while(arr.size() < 2 * C)
            arr.push_back(0);
        sort(arr.begin(), arr.end());
        int chamber = 0;
        for(int i=0,j=arr.size()-1;i<j;++i,--j,++chamber){
            vi weights = {arr[i],arr[j]};
            for(int weight : weights){
                if(weight != 0)
                    OUTPUT[chamber].push_back(weight);
            }
        }
        cout<<"Set #"<<t++<<'\n';
        for(int i=0;i<OUTPUT.size();++i){
            cout<<setw(2)<<i<<":";
            double currImb = 0;
            for(int j=0;j<OUTPUT[i].size();++j){
                cout<<" "<<OUTPUT[i][j];
                currImb += OUTPUT[i][j];
            }
            cout<<'\n';
            imb += fabs(currImb - avg);
        }
        cout<<"IMBALANCE = "<<fixed<<setprecision(5)<<imb<<"\n\n";
    }
}
