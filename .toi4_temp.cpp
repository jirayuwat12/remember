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
int M;
int data[20][20];
int maxtemp = -6;
void foo(int i,int j,int lasttemp = -6){
    if(i < 0 || i >= M || j < 0 || j >= M ) return;
    if(data[i][j] > lasttemp) {
        maxtemp = max(maxtemp, data[i][j]);
        foo(i+1,j,data[i][j]);
        foo(i-1,j,data[i][j]);
        foo(i,j+1,data[i][j]);
        foo(i,j-1,data[i][j]);
    }
}
int main( ){
    int posi,posj;
    cin>>M>>posj>>posi;
    posi--;
    posj--;
    FOR(i,0,M){
        FOR(j,0,M) {
            cin>>data[i][j];
            if(data[i][j] == 100) data[i][j] = -6;
        }
    }
    foo(posi,posj);
    cout<<maxtemp;
    return 0;
}
/*

*/