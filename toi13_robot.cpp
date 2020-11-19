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
int N,M;
int dist(const vector<vector<char>> &data,int i,int j,int walk,map<pair<int,int>,bool> vst){
    // cout<<i<<' '<<j<<'\n';
    if(i < 0 || j < 0 || i >= N || j >= M) return INT_MAX;
    if(data[i][j] == 'X') return walk;
    if(data[i][j] == 'W') return INT_MAX;
    int u,d,r,l;
    vst[{i,j}] = true;
    if(!vst[{i+1,j}]) u = dist(data,i+1,j,walk+1,vst);
    else u = INT_MAX;
    if(!vst[{i-1,j}]) d = dist(data,i-1,j,walk+1,vst);
    else d = INT_MAX;
    if(!vst[{i,j+1}]) r = dist(data,i,j+1,walk+1,vst);
    else r = INT_MAX;
    if(!vst[{i,j-1}]) l = dist(data,i,j-1,walk+1,vst);
    else l = INT_MAX;
    u = min(u,min(d,min(r,l)));
    // cout<<u<<'\n';
    return u ;
}
int main( ){
    cin>>N>>M;
    vector<vector<char>> data(N,vector<char>(M));
    vector<pair<int,int>> Apos;
    FOR(i,0,N){
        string n;
        cin>>n;
        FOR(j,0,M){
            data[i][j] = n[j];
            if(n[j] == 'A') Apos.push_back({i,j}); 
        }
    }
    int sum = 0; 
    int sum2 = 0;
    for(auto i : Apos){
        map<pair<int,int>,bool> vst;
        int d = dist(data,i.first,i.second,0,vst);
        if(d != INT_MAX) sum += d*2,sum2++;
    }
    cout<<sum2<<' '<<sum;
    
    return 0;
}
/*

*/