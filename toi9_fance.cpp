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
int n,m;
bool canit(map<pair<int,int>,bool> tr,int size){
    FOR(i,0,n-size+1){
        FOR(j,0,m-size+1){
            bool ck = true;
            FOR(ii,i,i+size){
                if(tr[{ii,j}] || tr[{ii,j+size-1}]) ck = false;
            }
            FOR(jj,j,j+size){
                if(tr[{i,jj}] || tr[{i+size-1,jj}]) ck = false;
            }
            
            if(ck) return ck;
        }
    }
    return false;
}
int main( ){
    int t =2;
    while(t--){
        cin>>n>>m;
        map<pair<int,int>,bool> mm;
        int tr;
        cin>>tr;
        while(tr--){
            int i,j;
            cin>>i>>j;
            mm[make_pair(i,j)] =true;
        }
        FORR(i,min(m,n),1){
            if(canit(mm,i)){ 
                cout<<i<<'\n';
                break;
            }
        }
    }
    return 0;
}
/*

*/