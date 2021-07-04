#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define xll __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define v(x) vector<x>
#define MATRIX(x) vector<vector<x>>
#define MATRIX3D(x) vector<vector<vector<x>>>
#define MAX(A,B,C) max(A,max(B,C))
#define MIN(A,B,C) min(A,min(B,C))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PREC 1e-9
struct print{
    bool clt, clb, crt, crb;
    bool rt,rm,rb;
    print(bool clt, bool clb, bool crt, bool crb, bool rt, bool rm, bool rb) {
        this->clt = clt;
        this->clb = clb;
        this->crt = crt;
        this->crb = crb;
        this->rt = rt;
        this->rm = rm;
        this->rb = rb;
    }
};
print nums[] = {
    print(1,1,1,1,1,0,1),
    print(0,0,1,1,0,0,0),
    print(0,1,1,0,1,1,1),
    print(0,0,1,1,1,1,1),
    print(1,0,1,1,0,1,0),
    print(1,0,0,1,1,1,1),
    print(1,1,0,1,1,1,1),
    print(0,0,1,1,1,0,0),
    print(1,1,1,1,1,1,1),
    print(1,0,1,1,1,1,1)
};
string printNum(int s, string num){
    string build;
    for(int i=0;i<(2 * s + 3);++i){
        bool first = true;
        for(char d : num){
            if(first)
                first = false;
            else
                build += " ";
            print nmap = nums[d-'0'];
            if(i == 0){
                if(nmap.rt)
                    build += string(1,' ') + string(s, '-') + string(1,' ');
                else
                    build += string(s + 2, ' ');
            }
            else if(i == s + 1){
                if(nmap.rm)
                    build += string(1,' ') + string(s, '-') + string(1,' ');
                else
                    build += string(s + 2, ' ');
            }
            else if(i == (2 * s + 2)){
                if(nmap.rb)
                    build += string(1,' ') + string(s, '-') + string(1,' ');
                else
                    build += string(s + 2, ' ');
            }
            else{
                if(i < s + 1){
                    build += (nmap.clt) ? string(1, '|') : string(1, ' ');
                    build += string(s, ' ');
                    build += (nmap.crt) ? string(1, '|') : string(1, ' ');
                }
                else{
                    build += (nmap.clb) ? string(1, '|') : string(1, ' ');
                    build += string(s, ' ');
                    build += (nmap.crb) ? string(1, '|') : string(1, ' ');
                }
            }
        }
        build += '\n';
    }
    return build;
}
int main(){
    int s;
    string n;
    while(cin >> s >> n && !(s == 0 && n == "0")){
        cout<<printNum(s, n)<<'\n';        
    }
}
