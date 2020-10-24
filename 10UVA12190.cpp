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
vector<pair<ll,ll>> cost = {{2,100}, {3,10000}, {5,1000000}, {7,0}};
ll cwh(int bill){
    ll cons = 0;
    cons += min(max(0, bill/2), 100); bill -= 2*100;
    cons += min(max(0, bill/3), 9900); bill -= 3*9900;
    cons += min(max(0, bill/5), 990000); bill -= 5*990000;
    cons += max(0, bill/7);
    return cons;
}
ll bill(int energy){
    int price = 0;
    price += min(max(0, energy*2), 2*100); energy -= 100;
    price += min(max(0, energy*3), 3*9900); energy -= 9900;
    price += min(max(0, energy*5), 5*990000); energy -= 990000;
    price += max(0, energy*7);
    return price;
}
ll bisection(ll A, ll B){
    ll totalConsum = cwh(A);
    ll left = 1;
    ll right = totalConsum;
    while(right - left > 1){
        ll mid = (left + right) >> 1;
        ll myBill = bill(mid);
        ll neighBill = myBill + B;
        ll neigh = cwh(neighBill);
        // cout<<left<<" "<<right<<" "<<mid<<' '<<myBill<<' '<<neighBill<<' '<<mid + neigh<<' '<<totalConsum<<'\n';
        if(mid + neigh < totalConsum)
            left = mid + 1;
        else if(mid + neigh > totalConsum)
            right = mid - 1;
        else
            right = mid;
    }
    ll myBill = bill(left);
    ll neighBill = myBill + B;
    ll neigh = cwh(neighBill);
    if(left + neigh == totalConsum)
        return myBill;
    else
        return myBill = bill(right);
}
int main(){
    ll A,B;
    while(cin >> A >> B && A != 0 && B != 0){
        cout<<bisection(A,B)<<'\n';
    }
    // cin >> A;
    // cout<<cwh(A)<<'\n';
}
