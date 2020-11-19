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
#define pb push_back
int n,m;
vector<vector<int>> G;
string inttostring(int i ){
    string ans = "";
    while(i){
        ans = ans + (char)(i % 10 +'0');
        i /=10;
    }
    if(ans.length( )==0) ans = "0";
    reverse(ans.begin( ),ans.end( ));
    return ans;
}
void DFS(int s,map<int,bool> vst,string ans = ""){
        if(G[s].size( )==1) {
            cout<<ans<<'\n';
            return;
        
        }
        ans += inttostring(s) + ' ';
        vst[s] = true;
        for(int i :G[s]){
            DFS(i,vst,ans);
        }
}
int main( ){
    // cout<<inttostring(0);
    cin>>n>>m;
    G = vector<vector<int>>(n);
    FOR(i,0,n){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    map<int,bool>vst;
    DFS(0,vst);
    return 0;
}
/*

*/