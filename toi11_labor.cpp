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

int M;
ll N;
ll data[1000001]; 
int main( ){
    cin>>M>>N;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> next_time;
    FOR(i,0,M){
        cin>>data[i];
        next_time.push({data[i],i});
    }
    while(N--){
        next_time.push({next_time.top( ).first + data[next_time.top( ).second],next_time.top( ).second});
        next_time.pop( );
    }
    ll maxx=0;
    while(!next_time.empty( )){
        maxx = max(maxx,next_time.top( ).first - data[next_time.top( ).second]);
        next_time.pop( );
    }
    cout<<maxx;

    return 0;
}
/*

*/