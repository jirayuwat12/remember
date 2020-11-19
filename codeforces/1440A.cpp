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
    int t;
    cin>>t;
    while(t--){
        int n,c0,c1,h;
        string s;
        cin>>n>>c0>>c1>>h>>s;
        int sum = 0;
        for(char i : s){

            if(i - '0' == 0 ){
                sum += min(c0,c1+h);
            }else{
                sum += min(c1,c0+h);
            }
        }
        cout<<sum<<"\n";
    }
    
    return 0;
}
/*

*/