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
#include <limits>
#include <math.h>
#include <utility>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;

vector<vector<double>> ss;

vector<vector<double>> data;
vector<vector<bool>>   vst;
int M,N;
double minprice = numeric_limits<double>::max( );
vector<double> power(15);

void foo(double nowprice = 0){
    bool ck = false;
    FOR(i,0,M){
        FOR(j,0,N){
            if(!vst[i][j]){
                ck = true;
                vst[i][j] = true;

                nowprice += data[i][j]*(power[ss[i][j]]);
               
                FOR(k,i-1,i+2){
                    FOR(l,j-1,j+2){
                        if(k < 0 || k >= M || l < 0 || l >= N) continue;
                        ss[k][l] ++;
                    }
                }

                foo(nowprice);

                FOR(k,i-1,i+2){
                    FOR(l,j-1,j+2){
                        if(k < 0 || k >= M || l < 0 || l >= N) continue;
                        ss[k][l] --;
                    }
                }

                nowprice -= data[i][j]*(power[ss[i][j]]);

                vst[i][j] = false;
            }
        }
    }

    if(!ck){
        minprice = min (minprice,nowprice);
    }
}


int main( ){
    
    cin>>M>>N;
    data = vector<vector<double>>(M,vector<double>(N));
    ss = vector<vector<double>>(M,vector<double>(N,0));
    vst = vector<vector<bool>>(M,vector<bool>(N,false));
    power[0] = 1;
    FOR(i,1,15){
        power[i] = power[i-1] * 1.1;
    }
    for(vector<double> &i : data) for(double &it : i ) cin>>it;
 
    foo( );

    printf("%.2f",minprice);
    return 0;
}
/*

*/