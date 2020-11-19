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
int M,N,K;
ll data[1000][1000];
ll dp[1000][1000];
int main( ){
    cin>>N>>M>>K;
    FOR(i,0,N){
        FOR(j,0,M) cin>>data[i][j];
    }
    FOR(i,K-1,N){
        FOR(j,0,M){
            if(i == K-1){
                ll sum = 0;
                FOR(k,i-K+1,i+1){
                    sum += data[k][j];
                }
                dp[i][j] = sum;
            }else{
                dp[i][j] = dp[i-1][j] +data[i][j] - data[i-K][j];
            }
        }
    }
    ll ans = LLONG_MIN;
    FOR(i,K-1,N){
        ll sum = 0;
        FOR(j,0,K) sum += dp[i][j];
        data[i][K-1] = sum;
        ans = max(ans,data[i][K-1]);
        FOR(j,K,M){
            data[i][j] = data[i][j-1] - dp[i][j-K] + dp[i][j];
            ans = max(data[i][j],ans); 
        }
    }
    // FOR(i,0,N){
    //     FOR(j,0,M) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }
    cout<<ans;
    return 0;
}
/*
5 10
2
5 9 2 9 1 2 8 9 1 6
9 1 3 9 8 4 2 1 5 7
2 7 9 3 8 5 2 7 6 8
1 6 2 1 7 7 1 9 4 1
8 5 2 3 9 8 5 6 3 3

0 0 0 0 0 0 0 0 0 0
14 10 5 18 9 6 10 10 6 13
11 8 12 12 16 9 4 8 11 15
3 13 11 4 15 12 3 16 10 9
9 11 4 4 16 15 6 15 7 4
*/