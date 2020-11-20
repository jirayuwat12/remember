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
int n,m;
map<int,bool> dontdoit;
vector<int> ans;
bool isin(int t){
    FOR(i,0,ans.size()){
        if(ans[i] == t)return true;
    }
    return false;
}
void foo(int nowindex=0){
    if(nowindex == n){
        FOR(i,0,n) cout<<ans[i]<<' ';
        cout<<'\n';
        return;
    }
    FOR(i,1,n+1){
        if(isin(i)) continue;
        if(nowindex == 0 && dontdoit[i]) continue;
        ans[nowindex] = i;

        foo(nowindex +1);

        ans[nowindex] = -1;
    }
}
int main( ){
    cin>>n>>m;
    ans = vector<int>(n);
    FOR(i,0,m){
        int t;
        cin>>t;
        dontdoit[t] = true;
    }
    foo( );
    return 0;
}
/*

*/