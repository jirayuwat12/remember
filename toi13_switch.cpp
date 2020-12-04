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
int n;
int data[5000000];
int main( ){
    cin>>n;
    string ss;
    cin>>ss;
    FOR(i,0,n) data[i] = ss[i]-'0';
    FOR(i,1,n+1){
        int s = i;
        bool k = true;
        FOR(j,0,n){
            if(s>= n) s =0;
            if(data[s++] != data[j]) {
                k = false;
                break;
            }
        }
        if(k) {
            cout<<i;
            break;
        }
    }
    return 0;
}
/*

*/