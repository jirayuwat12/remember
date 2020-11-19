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
int n,k;
vector<int> data,dp;
int main( ){
    cin>>n>>k;
    data = vector<int>(n);
    dp = vector<int>(n,INT_MAX);
    for(int &it : data) cin>>it;
    return 0;
}
/*
0 1 2 3 4 5 6 7 8 9

2 1 4 3 2 1 5 1 2 3
2 3 6 5 4 4 9 5
  
*/