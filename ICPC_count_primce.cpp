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
    string s = " 
    ";
    int n = s.length( );
        if(n==0) return 0;
        vector<int> m(10000,0);
        int maxsize = 0;
        int l = 0;
        int r = 0;
        while(r < n){
            m[s[r]] ++ ;
            cout<<l<<' '<<r<<m[s[r]]<<'\n';
            if(m[s[r]] > 1) {
                maxsize = max(maxsize,r-l);
                while(m[s[r]] > 1 && l < r) m[s[l]] --,l++;
            }
            r++;
        }
    cout<<maxsize;
    return 0;
}
/*

*/