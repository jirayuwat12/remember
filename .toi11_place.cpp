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
int M,N;
vector<pair<int,pair<int,int>>> Q;
ll sum = 0;
bool myComp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    return a.first > b.first;
}
void MST( ){
    vector<int> pr,rank;
    pr = vector<int>(N+1);
    FOR(i,0,N+1) pr[i] = i;
    rank = vector<int>(N+1,1);
    int index =0;
    FOR(i,01,N){
        int u = Q[index].second.first;
        int v = Q[index].second.second;
        int w = Q[index].first;
        index++;
        int pru=u;
        int prv=v;
        //find
        while(pr[pru] != pru) pru=pr[pru];
        while(pr[prv] != prv) prv=pr[prv];
        if(pru != prv){
            sum += w-1;
            //union
            if(rank[pru] >= rank[prv]){
                rank[pru] ++;
                pr[prv] = pru;
            }else{
                rank[prv] ++;
                pr[pru] = prv; 
            }
        }else i--;         
    }
}
int main( ){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    FOR(i,0,M){
        int u,v,w;
        cin>>u>>v>>w;
        Q.push_back({w,{u,v}});
    }
    sort(Q.begin( ),Q.end( ),myComp);
    MST( );
    cout<<sum;
    return 0;
}
/*

*/