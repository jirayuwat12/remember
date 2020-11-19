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
vector<ll> data;
int main( ){
    int n,q;
    cin>>n>>q;
    data = vector<ll>(n);
    FOR(i,0,n){
        cin>>data[i];
    }
    while(q--){
        int t,x;
        ll y;
        cin>>t>>x>>y;
        if(t==1){
            FORR(i,x-1,0){
                if(data[i] >= y) break;
                else data[i]=y;
            }
        }else{
            int sum=0;
            FOR(i,x-1,n){
                if(y >= data[i]) {
                    y -= data[i];
                    sum ++;
                }
            }
            cout<<sum<<'\n';
        }
    }
    return 0;
}
/*

*/