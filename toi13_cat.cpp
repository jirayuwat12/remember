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
int data[2000000];
bool can(int s){
    int last = -1;
    FOR(i,0,n) if(data[i]>s){
        if(last ==-1) last=data[i];
        else if(last!=data[i]) return false;
        else last =-1;
    }
    return true;
}
int main( ){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    FOR(i,0,n) cin>>data[i];
    int l  =*min_element(data,data+n);
    int r  =*max_element(data,data+n);
    if(can(0)) {
        cout<<0;
        return 0;
    }
    while(l<r){
        int m = l + (r-l)/2;
        if(can(m)) r = m;
        else l = m+1;
    }
    cout<<l;
    return 0;
}
/*

*/