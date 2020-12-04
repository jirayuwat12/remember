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
        if(n&1) {
            FORR(i,n,((n+1)/2)+1) cout<<i<<' ';
            cout<<((n+1)/2)-1<<' '<<(n+1)/2<<' ';
            FORR(i,((n+1)/2) -2,1) cout<<i<<' ';
        }
        else FORR(i,n,1)cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}
/*

*/