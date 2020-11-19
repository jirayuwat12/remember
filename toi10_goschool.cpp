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
vector<vector<int>> data;
map<pair<int,int>,bool> dp;
int m,n;
vector<int> aa(2500);
bool foo (int i = 0,int j = m,int index = 0){
    
}

int main( ){
    cin>>m>>n;
    m--;
    n--;
    int t;
    cin>>t;
    while(t--){
        int i,j;
        cin>>i>>j;
        dp[{i,j}] = true;
    }

    return 0;
}
/*

*/