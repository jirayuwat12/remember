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
#include <queue>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
int main( ){
    int n,m;

    cin>>n>>m;
    queue<int> data;
    FOR(i,1,n+1) data.push(i);
    while(!data.empty( )){
        FOR(i,1,m){
            data.push(data.front( ));
            data.pop();
        }
        cout<<data.front( )<<' ';
        data.pop( );
    }
    return 0;
}
/*

*/