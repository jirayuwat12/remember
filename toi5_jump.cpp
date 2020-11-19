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
int main( ){
    
    int N,K;
    cin>>N>>K;
    vector<bool> data(60001,false);
    queue<int> Q;
    FOR(i,0,N){
        int t;
        cin>>t;
        data[t] = true;
        Q.push(t);
    }
    int sum = 0;
    FOR(i,0,K){
        if(data[i]) sum ++;
    }
    int maxsum = sum;
    FOR(i,1,60001 -K+1){
        if(data[i-1]) sum --;

        if(data[i+K-1]) sum ++;
        
        maxsum = max(sum,maxsum);
    }
    cout<<maxsum -1;
    return 0;

}
/*

*/