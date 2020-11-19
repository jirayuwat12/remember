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
map<pair<int,int>,int> data;
void draw(int s,int h,int w,int o){
    FOR(i,s,s+w){
        FOR(j,0,h){
            data[{i,j}] += o;
        }
    }
}
int main( ){
    int n,t;
    
    cin>>n>>t;
    if(n*100 < t){
        cout<<0;
        return 0;
    }
    while(n--){
        int s,h,w,o;
        cin>>s>>h>>w>>o;
        draw(s,h,w,o);
    }
    int sum = 0;
    for(auto i : data ){
        if(i.second == t) sum++;
    }
    cout<<sum;
    return 0;
}
/*

*/