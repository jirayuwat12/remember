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
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
int main( ){
    int n;
    cin>>n;
    set<ll> s;
    vector<ll> nc(n);
    vector<ll> np(n);
    ll ncmin = LLONG_MAX;
    for(ll & it : nc) {
        cin>>it;
        ncmin = min(ncmin,it);
    }
    for(ll & it : np) {
        cin>>it;
        s.insert(it);
    } 
    ll minsum = LLONG_MAX;
    ll index ;
    for(int i : s){
        ll sum = 0;
        if(i > ncmin) continue;
        FOR(j,0,n){
            if(np[j] >= i) sum += np[j] - i;
            else sum += np[j] + nc[j] - i;
        }
        if(sum < minsum){
            minsum = sum;
            index = i;
        }else if(sum == minsum && index > i){
            index = i;
        }
    }
    cout<<index<<' '<<minsum;
    return 0;

}
/*

*/