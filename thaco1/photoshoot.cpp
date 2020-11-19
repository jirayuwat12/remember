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
vector<pair<int,int>> range;
int N,K;
int main( ){
    cin>>N>>K;
    FOR(i,0,K){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        range.push_back({l,r});
    }
    vector<int> t(N,-1);
    if(K != 2){
        vector<int> data(N);
        FOR(i,0,N) data[i] = i+1;
        ll real_sum  = -1;
        do{
            ll sum = 0;
            for(auto i : range){
                int maxx = INT_MIN;
                int minn = INT_MAX;
                FOR(j,i.first,i.second+1){
                    maxx = max(maxx,data[j]);
                    minn = min(minn,data[j]);
                }
                sum += maxx - minn;
            }
            if(sum > real_sum){
                real_sum = sum;
                FOR(i,0,N) t[i] = data[i];
            }
        }while(next_permutation(data.begin( ),data.end( )));
    }else{
        map<int,bool> used;
        int minn = max(range[0].first,range[1].first);
        int maxx = min(range[0].second,range[1].second);
        if(minn < maxx){
            t[minn] = 1;
            t[maxx] = N;
            used[1]=true;
            used[N]=true;
        }else{
            if(range[1].first < range[0].second){
                t[range[1].first] = N;
                t[range[1].second] = 1;
                t[range[0].first] = 2;
                used[N] = true;
                used[1] = true;
                used[2] = true;
            }else if(range[0].first <= range[1].second){
                t[range[0].first] = N;
                t[range[0].second] = 1;
                t[range[1].first] = 2;
                used[N] = true;
                used[1] = true;
                used[2] = true;
            }
        }
        FOR(i,0,N){
            if(t[i]==-1){
                FOR(j,1,N+1) {
                    if(!used[j]) {
                        t[i]=j;
                        used[j] = true;
                        break;
                    }
                }
            }
        }
    }
    for(int i : t) cout<<i<<' ';
    return 0;
}
/*
20 2
1 10
9 20

*/