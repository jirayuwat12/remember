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
int N,M,K;
//                  w       u           i    v ;-1if it is K member
priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>>>,greater<pair<int,pair<int,pair<int,int>>>>> Q;
vector<int> pr,rank_;
vector<int> Mans; 
vector<pair<int,int>> Kans;
ll sum = 0;
vector<int> Gmin;
map<int,bool> sub;

int findd(int i){
    while(pr[i] != i) i = pr[i];
    return i;
}
void unionn(int pri,int prj){
    if(rank_[pri] > rank_[prj]) {
        pr[prj] = pri;
        rank_[pri] ++;
    }else{
        pr[pri] = prj;
        rank_[prj] ++;
    }
}
void MST( ){
    pr = vector<int>(N);
    FOR(i,0,N) pr[i]=i;
    rank_ = vector<int>(N,-1);
    FOR(i,1,N){
        int w = Q.top( ).first;
        int u = Q.top( ).second.first;
        int __i = Q.top( ).second.second.first;
        int v = Q.top( ).second.second.second;
        Q.pop( );
        // cout<<w<<' '<<u<<' '<<_i<<' '<<v<<'\n';
        if(v==-1){//K member
            int index =-1;
            int maxdif = 0;
            FOR(_i,0,N){
                if(_i == u) continue;
                if(Gmin[_i] - w > maxdif && findd(_i) != findd(u)){
                    maxdif = Gmin[_i] -w;
                    index =_i;
                }
            }
            if(index ==-1){
                i--;
            }else{
                unionn(findd(index),findd(u));
                Kans.push_back({__i+1,u+1});
                sum +=w;
            }
        }else{
            int pru = findd(u);
            int prv = findd(v);
            if(pru==prv) i--;
            else{
                unionn(pru,prv);
                Mans.push_back(__i+1);
                sum += w;
            }
        }
    }
}
int main( ){
    cin>>N>>M>>K;
    Gmin = vector<int>(N,INT_MAX);
    FOR(i,0,M){
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        Gmin[u] = min(Gmin[u],w);
        Gmin[v] = min(Gmin[v],w);
        Q.push({w,{u,{i,v}}});
    }
    FOR(i,0,K){
        int u , w;
        cin>>u>>w;
        u--;
        Q.push({w,{u,{i,-1}}});
    }
    MST( );
    cout<<sum<<'\n'<<Mans.size( )<<'\n';
    for(int i : Mans) cout<<i<<'\n';
    cout<<Kans.size( )<<'\n';
    for(pair<int,int> i: Kans) cout<<i.first<<' '<<i.second<<'\n';
    return 0;
}
/*

*/