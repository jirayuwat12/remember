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
    vector<int> data(10000);
    FOR(i,0,10000) data[i] = i;
    data[501] = 500;
    data[502] = 500;
    int lower= *(upper_bound(data.begin( ),data.end( ),500));
    cout<<lower;
    return 0;
}
/*

*/