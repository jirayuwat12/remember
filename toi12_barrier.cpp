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
int main( ){
    int n,w;
    cin>>n>>w;
    vector<int> data(n+1);
    cin>>data[1];
    data[0] = 0;
    FOR(i,2,n+1){
        cin>>data[i];
        data[i] += data[i-1];
    }
    //FOR(i,0,n+1) cout<<data[i]<<' ';
    int rminlength = 0,rmaxprofit = 0;
    FOR(j,0,w){
        int maxprofit = 0;
        int minlength = j+1;
        FOR(i,1,n+1){
            if(i + j >= n+1) break;
            if(maxprofit < data[i+j]-data[i-1]){
                maxprofit = data[i+j] - data[i-1];
            }
        }
        if(maxprofit >= rmaxprofit){
            rmaxprofit = maxprofit;
            rminlength = minlength;
        }
    }
    cout<<rmaxprofit<<'\n'<<rminlength;
    return 0;
}
/*

*/