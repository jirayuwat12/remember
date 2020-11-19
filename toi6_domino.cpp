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
int n;
vector<vector<char>> data;
void foo(int nowrow =0){
    if(nowrow == n){
        char lastchar = 'a';
        FOR(i,0,n){
            if(lastchar == data[i][0] && lastchar == '|'){
                lastchar = '0';
                continue;
            }
            FOR(j,0,2){
                cout<<data[i][j];
            }
            cout<<'\n';
            lastchar = data[i][0];
        }
    }else{
        if(nowrow+1 < n){

        }
    }
}
int main( ){
    cin>>n;
    data = vector<vector<char>>(n,vector<char>('a'));
    return 0;
}
/*

*/