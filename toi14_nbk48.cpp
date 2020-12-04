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
vector<pair<int,int>> dp;
int N,Q;
int found(int target){
    int l = 0;
    int r = N-1;
    while(l < r){
        int m  = (l +r+1)/2;
        if(dp[m].first<=target) l = m;
        else r = m-1;
    }
    while(dp[r].first <= target && r+1 <N) r++;
    if(r == 0) return 0;
    return dp[r-1].second;
}
int main( ){
    cin>>N>>Q;
    int sum = 0;
    FOR(i,1,N+1) {
        int t;
        cin>>t;
        sum += t;
        dp.push_back({sum,i});
    }
    sort(dp.begin( ),dp.end( ));
    FOR(i,1,N){
        if(dp[i].second < dp[i-1].second )dp[i].second = dp[i-1].second;
    }
    // FOR(i,0,N) cout<<dp[i].first<<' '<<dp[i].second<<'\n';
    while(Q--){
        int q;
        cin>>q;
        int t = found (q);
        cout<<t<<'\n';
    }
    return 0;
}
/*

*/