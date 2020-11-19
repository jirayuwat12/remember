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
#include <set>
#include <cmath>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
vector<pair<ll,ll>> Mcoor;
vector<pair<ll,pair<ll,ll>>> Ncoor; // r x y
int M,N;
bool isin(ll x,ll y,ll x2,ll y2,ll r){
    ll d = x-x2,d2 = y-y2;
    d = d%25000;
    d2=d2%25000;
    r = r%25000;
    return (d*d + d2*d2 <= r*r );
}
string stringpower(string a,string b){
    
}
/*
2 1
1000000000
*/
int main( ){
    ll r = 25000*25000;
    cout<<r;
    cin>>M>>N;
    Mcoor = vector<pair<ll,ll>> (M);
    Ncoor = vector<pair<ll,pair<ll,ll>>> (N);
    set<int> data[M];
    FOR(i,0,M){
        cin>>Mcoor[i].first>>Mcoor[i].second;
    }
    FOR(i,0,N){
        cin>>Ncoor[i].second.first>>Ncoor[i].second.second>>Ncoor[i].first;
    }
    FOR(i,0,M){
        FOR(j,0,N){
            if(isin(Mcoor[i].first,Mcoor[i].second,Ncoor[j].second.first,Ncoor[j].second.second,Ncoor[j].first)){
                data[i].insert(j);    
            }
        }
    }
    ll minsum = LLONG_MAX;
    FOR(i,0,M){
        ll sum = 0;
        FOR(j,0,M){
            if(i==j) continue;
            ll inter = 0;
            for(int k : data[i]){
                if(data[j].find(k) == data[j].end( )) sum ++;
                else inter ++;
            }
            sum += data[j].size( ) - inter;
        }
        minsum = min(minsum,sum);
    }
    if(minsum == LLONG_MAX) minsum = 0;
    cout<<minsum;
    return 0;
}
/*

*/