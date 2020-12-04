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
#include <math.h>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;

int ans(ll n){
    int sum = 0;
    while(n != 1){
        if(n&1){
            n--;
            sum++;
        }else if(n==2) n--,sum++;
        else{
            n=1;
            sum +=2;
        }
    }
    return sum;
}

int main( ){
    int t;
    cin>>t;
    ll n;
    while(t--){
        cin>>n;
        cout<<ans(n)<<'\n';
    }
    return 0;
}
/*

*/