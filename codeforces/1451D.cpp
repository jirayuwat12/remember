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
int main( ){
    vector<int> dp(20000,-1);
    int t;
    cin>>t;
    while(t--){
        ll d,k;
        cin>>d>>k;
        ll x = 0;
        while((x+1)*k <=d) x++;
        ll y = 0;
        if(x*k != d) while( (x*x*k*k + (y+1)*(y+1)*k*k) <=(d*d) ) y++;
        // cout<<x<<' '<<y<<'\n';
        if(!((x+y) & 1)) cout<<"Utkarsh";
        else cout<<"Ashish";
        cout<<'\n';
    }
    return 0;
}
/*

*/