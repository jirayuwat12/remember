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

bool myComp(pair<int,int> a,pair<int,int> b){
    return a.first > b.first;
}

int main( ){
    int n;
    cin>>n;
    vector<pair<int,int>> data;
    while(n--){
        int x,y;
        cin>>x>>y;
        data.push_back(make_pair(x,y));
    }
    // cout<<'\n';
    sort(data.begin( ),data.end( ),myComp);
    int maxy = data[0].second;
    cout<<data[0].first<<' '<<data[0].second<<'\n';
    FOR(i,1,data.size( )){
        if(data[i].second >= maxy){
            cout<<data[i].first<<' '<<data[i].second<<'\n';
            maxy = data[i].second;
        }
    }
    return 0; 
}
/*

*/