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
        int n,k;
        cin>>n>>k;
        string a,b;
        //a -> b
        cin>>a>>b;
        if(*min_element(a.begin( ),a.end( )) > *min_element(b.begin( ),b.end( ))) cout<<"No";

        cout<<'\n';
    }
    return 0;
}
/*

*/