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
void flip(int x,int y,int exx,int exy){
    FOR(i,y,y+2){
        FOR(j,x,x+2){
            if(i==exy && j ==exx) continue;
            data[i][j] ^= 1;
        }
    }
}
bool backtrack(vector<vector<int>> oper,int x=0,int y=0,int numoper = 0){
    FOR(i,0,2){
        FOR(j,0,2){
            oper.push_back({x})
            flip(x,y,x+j,y+i);
            backtrack(oper,)
            flip(x,y,x+j,y+i);
        }
    }
}
int main( ){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>n>>m;
        string t;
        vector<vector<int>> oper;
        FOR(i,0,n){
            cin>>t;
            FOR(j,0,m){
                data[i][j] = t[j]-'0';
            }
        }
        backtrack(oper);

    }
    return 0;
}
/*

*/