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
#include <queue>
#include <utility>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;

int N,M;

int main( ){
    cin>>N>>M;
    vector<vector<bool>> data(N,vector<bool>(M));
    FOR(i,0,N){
        string n;
        cin>>n;
        FOR(j,0,M){
            data[i][j] = (n[j]=='1')?true:false;
        }
    }
    queue<pair<int,int>> Q;
    int sum = 0;
    FOR(i,0,N){
        FOR(j,0,M){
            if(data[i][j]){
                Q.push({i,j});
                while(!Q.empty( )){
                    int ii = Q.front( ).first;
                    int ij = Q.front( ).second;
                    Q.pop( );
                    if(ii < 0 || ij < 0 || ii >= N || ij >= M) continue;
                    if(data[ii][ij]){
                        data[ii][ij] = false;
                        Q.push({ii+1,ij});
                        Q.push({ii-1,ij});
                        Q.push({ii,ij+1});
                        Q.push({ii,ij-1});
                        Q.push({ii+1,ij+1});
                        Q.push({ii+1,ij-1});
                        Q.push({ii-1,ij+1});
                        Q.push({ii-1,ij-1});
                    }
                }
                sum ++;
            }
        }
    }
    cout<<sum;
    return 0;
}
/*

*/