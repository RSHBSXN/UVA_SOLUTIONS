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
class interval{
    public:
        double left,right;
};
int main(){
    int n,d;
    int t = 1;
    while(cin >> n >> d && n != 0 && d != 0){
        vector<interval> points(n);
        bool valid = true;
        for(interval &point : points){
            int x,y;
            cin >> x >> y;
            if(y > d){
                valid = false;
                continue;
            }
            point.left = x - sqrt(d * d - y * y);
            point.right = x + sqrt(d * d - y * y);
        }
        cout<<"Case "<<t++<<": ";
        if(valid){
            sort(points.begin(),points.end(),[](interval &a,interval &b){
                return a.right < b.right;
            });
            int circles = 1;
            long double Max = points[0].right;
            for(int i=1;i<n;++i){
                if(points[i].left > Max)
                    circles++,Max = points[i].right;
            }
            cout<<circles;
        }
        else
            cout<<-1;
        cout<<"\n";
    }
}
