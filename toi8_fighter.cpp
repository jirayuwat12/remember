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
    int p;
    cin>>p;
    int oddlife = p;
    int evenlife = p;
    p *= 2;
    int t;
    int combo = 0;
    bool lastisodd = 0;
    while(p --){
        cin>>t;
        if(t & 1) {//odd
            if(lastisodd) combo ++;
            else {
                combo = 1;
                lastisodd = true;
            }
            evenlife -= (combo >= 3)?3:1;
        }else{//even
            if(lastisodd) {
                combo = 1;
                lastisodd = false;
            }
            else combo++;
            oddlife -= (combo >= 3)?3:1;
        }

        if(evenlife <= 0) {
            cout<<1<<'\n'<<t;
            break;
        }else if(oddlife <= 0){
            cout<<0<<'\n'<<t;
            break;
        }
    }
    return 0;
}
/*

*/