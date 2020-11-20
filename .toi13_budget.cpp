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
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
vector<int> stp(vector<vector<pair<int,int>>> & G,int s){
    vector<int> dist (G.size( ),INT_MAX);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty( )){
        int u = q.front( );
        q.pop( );
        for(pair<int,int> it : G[u]){
            int v = it.first;
            int d = it.second;
            if(dist[u] + d <= dist[v]) {
                dist[v] = dist[u] + d;
                q.push(v);
            }
        }
    }
    return dist;
}
int main( ){
    int N,M,X,Y,Z;
    cin>>N>>M>>X>>Y>>Z;
    vector<vector<pair<int,int>>> graph(N);
    while(M--){
        int u,v,d;
        cin>>u>>v>>d;
        graph[u].push_back({v,d});
        graph[v].push_back({u,d});
    }
    vector<int> dist_from_X = stp(graph,X);
    vector<int> dist_from_Y = stp(graph,Y);
    if(dist_from_X[Y] <= Z){
        cout<<Y<<' '<<dist_from_X[Y]<<' '<<0;
    }else{
        int minindex;n
        int min = INT_MAX;
        FOR(i,0,N){
            if(Y == i) continue;
            if(dist_from_Y[i] < min && dist_from_X[i] <= Z){
                min= dist_from_Y[i];
                minindex = i;
            }
        }
        cout<<minindex<<' '<<dist_from_X[minindex]<<' '<<min;
    }
    return 0;
}
/*

*/