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
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;

int main( ){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> a,b;
    FOR(i,0,n){
        int t;
        cin>>t;
        a.push(t);
    }
    FOR(i,0,n){
        int t;
        cin>>t;
        b.push(t);
    }
    int sum = 0 ;
    while(n--){
        sum += abs(a.top( ) - b.top( ));
        a.pop( );
        b.pop( );
    }
    cout<<sum;
    return 0;
}
/*

*/