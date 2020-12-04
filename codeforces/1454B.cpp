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
        int n;
        cin>>n;
        map<int,int> m;
        FOR(i,1,n+1){
            int tt;
            cin>>tt;
            if(m[tt]) m[tt]=-1;
            else m[tt] = i;
        }
        bool ck = 0;
        for(auto i:m){
            if(i.second != -1) {
                ck = 1;
                cout<<i.first<<'\n';
                break;
            }
        }
        if(!ck){
            cout<<"-1\n";
        }
    }
    return 0;
}
/*

*/