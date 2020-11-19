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
int n,k;

vector<vector<int>> G;
vector<pair<int,int>> data;

ll MST( ){
    vector<int> key(n,INT_MAX);
    vector<bool> included(n,false);
    key[0] = 0;
    FOR(i,1,n){
        int u,minu = INT_MAX;
        FOR(j,0,n){
            if(!included[j] && minu > key[j]){
                u = j;
                minu= key[j];
            }
        }
        included[u] = true;
        FOR(j,0,n){
            if(u==j) continue;
            if(!included[j] && key[j] > G[u][j]){
                key[j] = G[u][j];
            }
        }
    }
    ll maxsum=0;
    sort(key.begin( ),key.end( ));
    FOR(i,0,n-k+1){
        maxsum +=key[i];
    }
    return maxsum;
}

int main( ){
    cin>>n>>k;
    data = vector<pair<int,int>> (n);
    G = vector<vector<int>> (n,vector<int>(n));
    FOR(i,0,n){
        cin>>data[i].first>>data[i].second;
        FOR(j,0,i){
            int dist = abs(data[i].first - data[j].first) + abs(data[j].second - data[i].second);
            G[i][j] = G[j][i] = dist;
        }
    }
    cout<<MST( );
    return 0;
}
/*
5 /RTE 50:05
80 /RTE 1:28:59

*/