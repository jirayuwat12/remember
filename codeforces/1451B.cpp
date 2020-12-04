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
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        while(q--){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            bool ck = false;
            for(int i=0;i<u;i++){
                if(s[i] == s[u]) ck = true;
            }
            for(int i = n-1;i>v;i--){
                if(s[i] == s[v]) ck = true;
            }
            if(ck) cout<<"YES";
            else cout<<"NO";
            cout<<'\n';
        }
    }
    return 0;
}
/*

*/