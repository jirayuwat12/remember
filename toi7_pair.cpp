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
bool mycomp(pair<int,int> a,pair<int,int> b){
    return a.first > b.first;
}
int main( ){
    int n;
    cin>>n;
    vector<pair<int,int>> data;
    FOR(i,0,n){
        int a,b;
        cin>>a>>b;
        data.push_back(make_pair(a,b));
    }
    sort(data.begin( ),data.end( ));
    long long sum = 0;
    for(auto i : data){
        cout<<i.first<<' '<<i.second<<'\n';
    }
    cout<<sum;
    return 0;
}
/*

*/