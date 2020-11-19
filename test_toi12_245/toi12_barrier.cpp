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

int N,W;
vector<int> data;
int maxvalue = INT_MIN;
int minleght = 1;

int main( ){
    cin>>N>>W;
    data = vector<int>(N);
    for(auto &it : data) {
        cin>>it;
        maxvalue = max(maxvalue,it);
    }
    if(maxvalue <= 0 ) cout<<0<<'\n'<<0;
    else{
        FOR(lenght,2,W+1){
            int nowvalue = 0;
            FOR(i,0,lenght) nowvalue += data[i];
            if(nowvalue > maxvalue) {
                maxvalue = nowvalue;
                minleght = lenght;
            }
            FOR(i,lenght,N){
                nowvalue = nowvalue - data[i-lenght] + data[i];
                if(nowvalue > maxvalue) {
                    maxvalue = nowvalue;
                    minleght = lenght;
                }
            }
        }
        cout<<maxvalue<<'\n'<<minleght;
    }
    return 0;
}
/*
60  / time limit exceeded 11:29

*/