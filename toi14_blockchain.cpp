/*
Auther : Jirayuwat Boonchan
IG : _p_pp_pp
PB : Jirayuwat Boonchan
Email : Jirayuwat12@gmail.com
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <utility>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;

int main( ){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,Q;
    cin>>T>>Q;
    map<set<pair<int,int>>,int> temp;
    while(T--){
        set<pair<int,int>> tset;
        int n;
        cin>>n;
        FOR(i,1,n){
            int x,y;
            cin>>x>>y;
            tset.insert({min(x,y),max(x,y)});
        }
        temp[tset] ++;
    }
    while(Q--){
        set<pair<int,int>> tset;
        int n;
        cin>>n;
        FOR(i,1,n){
            int x,y;
            cin>>x>>y;
            tset.insert({min(x,y),max(x,y)});
        }
        cout<<temp[tset]<<'\n';
    }
    
    return 0;
}
/*

*/