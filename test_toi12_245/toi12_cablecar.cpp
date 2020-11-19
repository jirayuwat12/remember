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
#include <math.h>
#include <utility>
#include <queue>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
int start,target,number;
int V,E;
vector<vector<int>> data;
priority_queue<pair<int,pair<int,int>>> Q;
int minbyway = INT_MAX;

int find(vector<int> &parent,int i){
    while(parent[i] != i) i = parent[i];
    return i;
}
int unionn(vector<int> &parent,vector<int> &rank,int i,int j){
    if(rank[i] >= rank[j]) {
        parent[j] = i;
        rank[i] ++;
    }else{
        parent[i] =j;
        rank[j] ++;
    }
}

void DFS(int s,int t){
    queue<pair<int,int>> Q;
    Q.push({s,INT_MAX});
    map<int,bool> vst;
    while(!Q.empty( )){
        int minn = Q.front( ).second;
        int now = Q.front( ).first;
        Q.pop( );
        vst[now] = true;

        if(now==t){
            minbyway = minn;
            return;
        }
        FOR(i,0,V){
            if(data[now][i]!= -1 && !vst[i]){
                Q.push({i,min(minn,data[now][i])});
            }
        }
    }
}

void MaST( ){
    vector<int> parent(V);
    FOR(i,0,V) parent[i] = i;
    vector<int> rank(V,1);
    FOR(i,1,V){
        int u,v,w;
        w = Q.top( ).first;
        u = Q.top( ).second.first;
        v = Q.top( ).second.second;
        Q.pop( );
        int pru = find(parent,u);
        int prv = find(parent,v);
        if(pru != prv){
            data[u][v] = w;
            data[v][u] = w;
            unionn(parent,rank,pru,prv);
        }else i--;
    }
}

int main( ){
    cin>>V>>E;
    data = vector<vector<int>>(V,vector<int>(V,-1));
    FOR(i,0,E){
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        Q.push({w,{u,v}});
    }
    MaST( );
    cin>>start>>target>>number;
    start--;
    target--;
    DFS(start,target);
    // cout<<minbyway;
    minbyway --;
    cout<<(ceil((double)number/minbyway));
    // for(auto i : data){
    //     for(auto j : i) cout<<j<<'\t';
    //     cout<<'\n';
    // }

    return 0;
}
/*
100 / act : 1:00:15
*/