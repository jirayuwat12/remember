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
#define pb push_back
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
int find(vector<int> &pr,int t){
    while(pr[t] != -1) t = pr[t];
    return t; 
}
int main( ){
    //input
    int V,E;
    cin>>V>>E;
    vector<pair<int,pair<int,pair<int,int>>>> G;
    while(E--){
        int u,v,w,s;
        cin>>u>>v>>w>>s;
        G.pb({!s,{w,{u,v}}});
    }
    int p;
    cin>>p;
    vector<pair<int,int>> price(p);
    for(auto &it : price){
        cin>>it.second>>it.first;
    }
    sort(price.begin( ),price.end( ));
    //change weight to price
    for(auto &it : G){
        for(auto pp : price){
            if(pp.second >= it.second.first){
                it.second.first = pp.first;
                break;
            }
        }
    }
    sort(G.begin( ),G.end( ));
    //MST
    ll sum = 0;
    vector<int> pr(V,-1);
    vector<int> rank(V,0);
    for(pair<int,pair<int,pair<int,int>>> it : G){// status weight u v
        int pru = find(pr,it.second.second.first);
        int prv = find(pr,it.second.second.second);
        if(pru != prv){
            if(rank[pru] >= rank[prv]){
                pr[prv] = pru;
                rank[pru] ++;
            }else{ 
                pr[pru] = prv;
                rank[prv] ++;
            }
            if(it.first) sum += it.second.first;
        }
    }
    cout<<sum;
    return 0;
}
/*

*/