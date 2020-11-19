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
#include <math.h>
#include <utility>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
int toint(string a){
    int k = a.length( );
    int sum = 0;
    FOR(i,0,k){
        cout<<a[i]<<' '<<i<<' '<<k-i-1<<' '<<pow(10,k-i-1)<<'\n';
        sum += (a[i]-48) * pow(10,k-i-1);
    }
    cout<<sum<<'\n';
}
int main( ){
    toint("999");
    return 0;
}
/*

*/