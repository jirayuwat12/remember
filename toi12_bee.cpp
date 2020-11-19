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
    int t;
    cin>>t;
    ll data[24][2];
    data[0][0] = 2;
    data[0][1] = 1;
    FOR(i,1,24){
        data[i][0] = data[i-1][0] + 1 + data[i-1][1];
        data[i][1] = data[i-1][0];
        //cout<<data[i][0]<<' '<<data[i][1]<<'\n';
    }
    while(t != -1) {
        cout<<data[t-1][0]<<' '<<data[t-1][0]+1+data[t-1][1]<<'\n';
        cin>>t;
    }

    return 0;
}
/*

*/