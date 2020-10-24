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
#define v(type) vector<type>
#define MATRIX(type) v(v(type))
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PREC 1e-9
int main(){
    int n;
    cin >> n;
    char frst = -1;
    while(n--){
        string str;
        cin >> str;
        char res;
        vector<string> pos = {"1", "4", "78"};
        if(find(pos.begin(), pos.end(), str) != pos.end())
            res = '+';
        else if(str.length() > 2 && str[str.length()-2] == '3' && str[str.length() - 1] == '5')
            res = '-';
        else if(str[0] == '9' && str[str.length()-1] == '4')
            res = '*';
        else if(str.length() > 3 && str.substr(0, 3) == "190")
            res = '?';
        else
            res = frst;
        if(frst == -1)
            frst = res;
        cout<<res<<'\n';
    }
}
