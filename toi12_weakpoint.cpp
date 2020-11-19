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
vector<vector<int>> G;
vector<bool> arti;
vector<bool> vst ( 500001,false);
vector<int> 
int N,M;
int DFS1(int start){
    vst[i] = true;
    for(int i : G[start]){
        if(!vst[i])
    }
} 

int DFS2(int start,int except){

}
int main( ){
    cin>>N>>M;
    G = vector<vector<int>>(N+1);
    arti = vector<bool> (N+1,false);
    FOR(i,0,N){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    return 0;
}
/*

*/