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
#include <math.h>
#include <limits.h>
#include <utility>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;



int main( ){
    int n;
    cin>>n;

    vector<bool> data(7368788,false);
    FOR(i,2,7368788){
        if(!data[i]) n--;
        if(n == 0) {
            cout<<i;
            return 0;
        }
        for(int j = i ;j<7368788;j+=i){
            data[j] = true;
        }
    }
    return 0;
}
/*
2 3 5 7 9 11    
*/