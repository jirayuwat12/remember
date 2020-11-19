/*
author : Jirayuwat Boonchan
school : PSU.Wit
topic  : 
Big O  : n(nlogn)
*/
#include <bits/stdc++.h>
#define FOR(i,s,n) for(int i=s;i<n;i++)
#define FORR(i,s,n) for(int i=s;i>=n;i--)
#define pb push_back
#define MOD 1000000007
using namespace std;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef vector<int> vi;
typedef tuple<int,int,int> tiii;
bool temp[10000000];
int main( ) {
    // freopen("C:\\Users\\Jirayuwat\\Desktop\\testcase-cannon\\1.in","r",stdin);
    int N,M,K,L;
    cin>>N>>M>>K>>L;
    vector<int> log(N);
    for(auto &it : log) cin>>it;
    while (K--){
        int ans = 0;
        memset(temp,false,sizeof(bool)*10000000);
        FOR(i,0,M){
            int t;
            cin>>t;
            int indexup  = upper_bound(log.begin( ),log.end( ),t+L)- log.begin( );
            int indexlow = lower_bound(log.begin(),log.end( ),t-L) - log.begin( );
            // cout<<t<<" : ";
            FOR(i,indexlow,indexup){
                if(!temp[i] ) ans++;
                temp[i] = true;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
3 2 4 100
100 300 500 -> 0-200 200-400 400-600
200 1000
199 1000
200 600
1000 1001
*/