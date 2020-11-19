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
int main( ){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int numberofhand = n/k;
        if(m==0 || m==n) cout<<0<<'\n';
        else{
            if(m - numberofhand <= 0 ) cout<<m<<'\n';
            else{
                m -=  numberofhand;
                m = (m+k-1)/(k-1);
                cout<<numberofhand - m<<'\n';
            }
        }
    }
    return 0;
}
/*

*/