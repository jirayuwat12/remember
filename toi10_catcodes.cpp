/*
Auther : Jirayuwat Boonchan
IG : _p_pp_pp
PB : Jirayuwat Boonchan
Email : Jirayuwat12@gmail.com
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
#include <utility>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
int main( ){
    int k,m;
    vector<string> db;
    cin>>k>>m;
    string str;
    while(k--){
        cin>>str;
        db.push_back(str);
    }
    sort(db.begin( ),db.end( ));
    int n;
    cin>>n;
    while(n--){
        int d;
        cin>>d>>str;
        FOR(i,0,d){
            int j = 0;
            if(str[i] == db[j]) 
        }
    }
    return 0;
}
/*

*/