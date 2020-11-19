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
#include <queue>
#include <utility>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
int n,k;

int main( ){
    map<int,bool> used;
    cin>>n>>k;
    priority_queue<int> minn;
    priority_queue<int,vector<int>,greater<int>> maxx;
    int l1,l2;
    cin>>l1>>l2;
    if(l1>l2 && !used[l1]) {
        minn.push(l1);
        maxx.push(l1);
        used[l1] = true;
    }
    int l3;
    FOR(i,2,n-1){
        cin>>l3;
        if(l2 > l1 && l2 > l3 && !used[l2]){
            minn.push(l2);
            maxx.push(l2);
            used[l2] = true;
        }
        l1 = l2;
        l2 = l3;
    }
    cin>>l3;
    if(l2>l1 && l2 > l3 && !used[l2]) {
        minn.push(l2);
        maxx.push(l2);
        used[l2] = true;
    }
    if(l3 > l2 && !used[l3]) {
        minn.push(l3);
        maxx.push(l3);
        used[l3] = true;
    }
    if(minn.size( ) == 0){
        cout<<-1;
    }else if(minn.size( ) < k){
        while(!maxx.empty( )){
            cout<<maxx.top( )<<'\n';
            maxx.pop( );
        }
    }else{
        while(k--){
            cout<<minn.top( )<<'\n';
            minn.pop( );
        }
    }
    
    return 0;
}
/*
90 / TLE 16:13
*/