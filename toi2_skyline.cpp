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
    vector<int> data(256,0);
    int maxr = 0;
    while(t--){
        int l,r,h;
        cin>>l>>h>>r;
        maxr = max(maxr,r);
        FOR(i,l,r+1) data[i] = max(data[i],h); 
    }
    // int nowh = -1;
    // FOR(i,1,maxr+1){
    //     if(nowh != data[i]) {
    //         cout<<i<<' '<<data[i]<<' ';
    //         nowh = data[i];
    //     }
    // }
    FOR(i,1,maxr+2) cout<<data[i]<<' ';
    return 0;
}
/*
8
1 11 5
2 6 7
12 7 16
14 3 25
19 18 22
3 13 9
23 13 29
24 4 28

2
1 11 5
2 6 7

*/