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
#include <math.h>
#include <utility>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
int n,m;
int main( ){
    cin>>m>>n;
    // data = vector<vector<int>>(n,vector<int>(4,0));
    map<int,map<int,int>> data;
    while(m--){
        int x,s,t;
        cin>>x>>s>>t;
        if(x==2){
            FOR(i,s,t+1){
                data[i][0] ++;
            }
        }else if(x == 3){
            FOR(i,s,t+1){
                data[i][1] ++;
            }
        }else if(x == 4){
            FOR(i,s,t+1){
                data[i][0] +=2;
            }
        }else if(x == 5){
            FOR(i,s,t+1){
                data[i][2] ++;
            }
        }else if(x == 6){
            FOR(i,s,t+1){
                data[i][0] ++;
                data[i][1] ++;
            }
        }else if(x == 7){
            FOR(i,s,t+1){
                data[i][3] ++;
            }
        }else if(x == 8){
            FOR(i,s,t+1){
                data[i][0] +=3;
            }
        }else if(x == 9){
            FOR(i,s,t+1){
                data[i][1] +=2;
            }
        }else if(x == 10){
            FOR(i,s,t+1){
                data[i][0] ++;
                data[i][2] ++;
            }
        }
    }
    ll max = 0;
    ll maxcount = 0;
    for(auto i : data){
        ll sum = 1;
        FOR(j,0,4){
            sum *= (i.second[j]+1);
        }
        if(max <sum) max = sum,maxcount = 1;
        else if(max == sum) maxcount ++;
    }
    cout<<max<<' '<<maxcount;
    return 0;

}
/*
2 3 4 5 6 7 8 9 10
2 3 2 5 2 7 2 3 2 
    2   3   2 3 5
            2
*/