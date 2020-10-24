#include <iostream>
#include <vector>
using namespace std;
int main(){
    string str;
    cin >> str;
    cout<<str<<'\n';
}
/*
SELECT * FROM Artist WHERE ArtistId NOT IN (SELECT ArtistId FROM ALBUM);
*/
