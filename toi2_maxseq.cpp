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
    vector<int> data(t);
    for(int & i : data) cin>>i;
    int rl = 0;
    int rr = 0;
    int cl = 0;
    int cr = 0;

    int maxsum = 0;
    int maxdata= -200;
    FOR(i,0,t){
        maxsum += data[i];
        if(maxsum < 0) {
            maxsum = 0;
            cl = i+1;
        }else if(maxsum > maxdata){
            rr = i;
            rl = cl;
            maxdata = maxsum;
        }
    }
    if(maxdata > 0){
        FOR(i,rl,rr+1) cout<<data[i]<<' ';
        cout<<'\n'<<maxdata;
    }else cout<<"Empty sequence";
    return 0;
}
/*
8
4 -6 3 -2 6 -4 -6 6



3
-2 -3 -1
*/