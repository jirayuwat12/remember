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
#include <queue>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;--)
typedef long long ll;
int v,E,U,V,Z;
vector<vector<pair<int,int>>> G;
vector<int> STP(int s){
    vector<int> dist(v,1e9);
    dist[s] = 0;
    typedef pair<int,int> pi;
    priority_queue<pi,vector<pi>,greater<pi>> Q;
    Q.push({dist[s],s});
    while(!Q.empty( )){
        if(Q.top( ).first != dist[Q.top( ).second]) {
            Q.pop( );
            continue;
        }
        int u = Q.top( ).second;
        Q.pop( );
        int vv,w;
        for(pair<int,int> it : G[u]){
            vv = it.first;
            w = it.second;
            if(dist[u] + w < dist[vv]){
                dist[vv] = dist[u] + w;
                Q.push({dist[vv],vv});
            }
        }
    }
    return dist;
}
int main( ){
    cin>>v>>E>>U>>V>>Z;
    G.resize(v);
    FOR(i,0,E){
        int u,vv,w;
        cin>>u>>vv>>w;
        G[u].push_back({vv,w});
        G[vv].push_back({u,w});
    }    
    vector<int> distfU = STP(U);
    vector<int> distfV = STP(V);
    if(distfU[V]<=Z) cout<<V<<' '<<distfU[V]<<' '<<0;
    else{
        int minn=1e9,ind ;
        FOR(i,0,v){
            if(distfV[i] < minn && distfU[i] <= Z){
                minn = distfV[i];
                ind=i;
            }
        }
        cout<<ind<<' '<<distfU[ind]<<' '<<distfV[ind];
    }
    return 0;
}
/*

*/