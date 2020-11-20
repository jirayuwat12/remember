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
int M,O;
int data[101];
bool can(int mid){
    int ans = 0;
    int nowsum = 0;
    FOR(i,0,O){
        nowsum += data[i];
        if(nowsum > mid){
            nowsum = data[i];
            ans++;
        }
        if(mid < data[i]) return false;
    }
    // cout<<mid<<':'<<ans<<'\n';
    if(nowsum > 0) ans ++; 
    if(ans > M) return false;
    return true;
}
int main( ){
    cin>>M>>O;
    int l = 0;
    int r = 0;
    FOR(i,0,O){
        cin>>data[i];
        r += data[i];
    }
    while(l+1 < r){
        int mid = l + (r-l)/2;
        if(can(mid)) r = mid;
        else l = mid;
    }
    cout<<(l+r+1)/2;
    return 0;
}
/*

*/