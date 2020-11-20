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
int k;
int numwin;
int numlose;
void foo(int nowwin,int nowlose,string ans = ""){
    if(nowlose==k || nowwin==k) {
        cout<<ans<<'\n';
        return;
    }
    foo(nowwin+1,nowlose,ans+"W ");
    foo(nowwin,nowlose+1,ans+"L ");
}
int main( ){
    cin>>k>>numwin>>numlose;
    foo(numwin,numlose);
    return 0;
}
/*

*/