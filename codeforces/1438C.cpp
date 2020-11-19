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
int data[100][100];
int n,m;
int mt[100][100];
int main( ){
    int t;
    cin>>t;
    FOR(j,0,100) mt[0][j] = (j&1);
    FOR(i,1,100){
        FOR(j,0,100){
            mt[i][j] = ((mt[i-1][j]+1) & 1);
        }
    }
    while(t--){
        cin>>n>>m;
        FOR(i,0,n) FOR(j,0,m) cin>>data[i][j];
        
        FOR(i,0,n) {
            FOR(j,0,m){
                if(mt[i][j] == 1 && (data[i][j]&1)) data[i][j]++;
                if(mt[i][j] == 0 && ((data[i][j]&1)==0)) data[i][j] ++;  
                cout<<data[i][j]<<' ';
            }
            cout<<'\n';
        }
        FOR(i,0,n){
            FOR(j,0,m){
                
                cout<<data[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}
/*

*/