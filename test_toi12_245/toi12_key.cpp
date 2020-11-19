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
#include <queue>
#include <utility>
#include<stack>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;

string a,b;
stack<pair<int,pair<int,int>>> Q;

bool check(string inp){
    Q.push({0,{0,0}});
    bool ck = false;
    while(!Q.empty( )){
        int iinps = Q.top( ).first;
        int ia=Q.top( ).second.first;
        int ib=Q.top( ).second.second;
        Q.pop( );
        if(iinps == (int)inp.length( )) {
            ck = true;
            while(!Q.empty( )) Q.pop( );
            break;
        } 
        if(ia < (int)a.length( )) {
            if(inp[iinps] == a[ia]) Q.push({iinps+1,{ia+1,ib}});
        }
        if(ib < (int)b.length( )) {
            if(inp[iinps] == b[ib]) Q.push({iinps+1,{ia,ib+1}});
        }
    }
    return ck;
}
map<string,bool> data;
int main( ){
    cin>>a>>b;
    int k;
    cin>>k;
    while(k--){
        string inp; 
        cin>>inp;
        if(data[inp]) cout<<"Yes\n";
        else{
            if(check(inp)) {
                cout<<"Yes\n";
                data[inp] = true;
            }
            else cout<<"No\n";
        }
    }
}
/*
30 / TLE 24:48
45 / RTE 1:44:52
85 / TLE 2:07:45
*/