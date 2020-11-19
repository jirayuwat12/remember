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
int main( ){
    map<pair<int,int>,int>data;    
    FOR(__i,0,5){
        int n;
        cin>>n;
        FOR(i,1,n){
            int u,v;
            cin>>u>>v;
            if( u > v) swap(u,v);
            data[make_pair(u,v)] ++;
        }
        FOR(i,1,n){
            int u,v;
            cin>>u>>v;
            if( u > v) swap(u,v);
            data[make_pair(u,v)] --;
        }
        bool ck = true;
        for(auto &i : data){
            if(i.second) {
                ck = false;
                i.second = 0;
            }
        }
        if(ck) cout<<'Y';
        else cout<<'N';
    }
    return 0;
}
/*

*/