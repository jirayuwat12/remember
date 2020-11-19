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
int n;
int m;
vector<vector<int>> G;
vector<pair<int,pair<int,int>>> point;
vector<pair<int,pair<int,int>>> data;

int minpay = INT_MAX;
map<int,bool> vst;
void DFS(int start = 0,int M=0,int K=0,int C=0,int nowpay =0){
    if(nowpay >= minpay) return;
    if(min(M,min(K,C)) >= n){
        minpay = min(minpay,nowpay);
        return;
    }
    vst[start] = true;
    FOR(i,0,m+1){
        if(!vst[i]){
            DFS(i,M+data[i].first,K+data[i].second.first,C+data[i].second.second,nowpay+G[start][i]);
        }
    }
    vst[start] = false;
}

int main( ){
    cin>>n;
    int x,y,z;
    cin>>x>>y>>z;
    cin>>m;
    G = vector<vector<int>>(m+1,vector<int>(m+1));
    point = vector<pair<int,pair<int,int>>> (m+1);
    data = vector<pair<int,pair<int,int>>> (m+1);
    point[0] =  {x,{y,z}};
    data[0]  =  {0,{0,0}};
    FOR(i,1,m+1){
        cin>>x>>y>>z;
        int M,K,C;
        cin>>M>>K>>C;
        point[i] = {x,{y,z}};
        data[i]  = {M,{K,C}};
    }
    FOR(i,0,m+1){
        FOR(j,0,m+1){
            G[i][j] = (point[i].first -         point[j].first        )*(point[i].first -         point[j].first);
            G[i][j]+= (point[i].second.first -  point[j].second.first )*(point[i].second.first -  point[j].second.first);
            G[i][j]+= (point[i].second.second - point[j].second.second)*(point[i].second.second - point[j].second.second);
        }
    } 
    // FOR(i,0,m+1){
    //     FOR(j,0,m+1){
    //         cout<<G[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    DFS( );
    cout<<minpay;
    return 0;
}
/*

*/