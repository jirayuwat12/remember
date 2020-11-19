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
vector<int> data;
int main( ){
    cin>>M>>O;
    data = vector<int>(O);
    for(int &it : data) cin>>it;

    return 0;
}
/*
3 4
800 400 400 700
800
800
700
max = 2300
min = 800
min         max         mid
800         2300        1550
800         1550        1175
800         1175        988
888         988         893
800         893         850
*/