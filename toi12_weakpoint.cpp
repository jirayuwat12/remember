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
vector<vector<int>> G;
int n,m;
int DFS(int start,int except){
    map<int,bool> vst;
    int sum =1;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty( )){
        sum ++;
        int u = Q.front( );
        Q.pop( );
        vst[u] = true;
        for(int v : G[u]){
            if(!vst[v] && v != except){
                Q.push(v);
            }
        }
    }
    return sum;
}
int main( ){
    cin>>n>>m;
    G = vector<vector<int>>(n+1);
    FOR(i,0,n){
        int u,v;
        cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    int maxnum = -1;
    int index;
    FOR(i,1,n+1){
        if(i==m) continue;
        int t = DFS(m,i);
        if(maxnum < n-t){
            maxnum = n-t;
            index = i;
        }
    }
    cout<<index<<'\n'<<maxnum;
    return 0;
}
/*
4 2
3 2
1 2
1 4
3 4

*/