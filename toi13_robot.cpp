/*
Auther : Jirayuwat Boonchan
IG : _p_pp_pp
PB : Jirayuwat Boonchan
Email : Jirayuwat12@gmail.com
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
#include <utility>
#include <queue>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
int N,M;
vector<string>G;
vector<pair<int,int>> x;
ll BFS(int i,int j){
    queue<pair<int,pair<int,ll>>> q;
    vector<vector<bool>> vst(N,vector<bool>(M,false));
    q.push({i,{j,0}});
    while(!q.empty( )){
        i = q.front( ).first;
        j = q.front( ).second.first;
        ll w = q.front( ).second.second;
        q.pop( );
        if(vst[i][j] || G[i][j]=='W') continue;
        vst[i][j] = true;
        if(G[i][j]=='X') return 2*w;
        w++;
        if(i) q.push({i-1,{j,w}});
        if(i<N-1) q.push({i+1,{j,w}});
        if(j) q.push({i,{j-1,w}});
        if(j<M-1) q.push({i,{j+1,w}});
    }
    return 0;
}
int main( ){
    cin>>N>>M;
    G.resize(N);
    
    for(int i =0;i<N;i++) {
        cin>>G[i];
        for(int j =0;j<M;j++){
            if(G[i][j]=='A') x.push_back({i,j});
        }
    }
    ll sum = 0;
    ll sum2 = 0;
    for(auto i : x){
        ll s = BFS(i.first,i.second);
        if(s) sum++,sum2+=s;
    }
    cout<<sum<<' '<<sum2;
    return 0;
}
/*
80
*/