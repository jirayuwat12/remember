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
int M,N;
int is,js,ie,je;
int sum = 0 ;
int stp = INT_MAX;
int data[151][151];
map<pair<int,int>,bool> vst;
vector<vector<int>> dp;
void BFS(int i,int j){
    queue<pair<int,int>> Q;
    Q.push({i,j});
    dp[i][j] = -1;
    while(!Q.empty( )){
        i = Q.front( ).first;
        j = Q.front( ).second;
        Q.pop( );
        if(i+1 <  N && data[i+1][j] ==1 &&dp[i+1][j]==-0) dp[i+1][j] = dp[i][j] -1,Q.push({i+1,j});
        if(i-1 >= 0 && data[i-1][j] ==1 &&dp[i-1][j]==-0) dp[i-1][j] = dp[i][j] -1,Q.push({i-1,j});
        if(j+1 <  M && data[i][j+1] ==1 &&dp[i][j+1]==-0) dp[i][j+1] = dp[i][j] -1,Q.push({i,j+1});
        if(j-1 >= 0 && data[i][j-1] ==1 &&dp[i][j-1]==-0) dp[i][j-1] = dp[i][j] -1,Q.push({i,j-1});
    }
}
void check_if_connect(int i ,int j);
void BFS2(int i,int j){
    queue<pair<int,int>> Q;
    Q.push({i,j});
    dp[i][j] = 1;
    while(!Q.empty( )){
        i = Q.front( ).first;
        j = Q.front( ).second;
        Q.pop( );

        check_if_connect(i,j);

        if(i+1 <  N && data[i+1][j] ==1 &&dp[i+1][j]==0) dp[i+1][j] = dp[i][j] +1,Q.push({i+1,j});
        if(i-1 >= 0 && data[i-1][j] ==1 &&dp[i-1][j]==-0) dp[i-1][j] = dp[i][j] +1,Q.push({i-1,j});
        if(j+1 <  M && data[i][j+1] ==1 &&dp[i][j+1]==-0) dp[i][j+1] = dp[i][j] +1,Q.push({i,j+1});
        if(j-1 >= 0 && data[i][j-1] ==1 &&dp[i][j-1]==-0) dp[i][j-1] = dp[i][j] +1,Q.push({i,j-1});
    }
}

void check_if_connect(int i,int j){
    bool ck;
    if(i-1 >= 0 && data[i-1][j] == 0){//top
        //now (i-1,j)
        ck = false;
        if(i-2 >= 0 && dp[i-2][j] < 0){//top
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i-2][j]));
        }
        if(j-1 >=0 && dp[i-1][j-1] <0){//left
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i-1][j-1]));
        }
        if(j+1 < M && dp[i-1][j+1] < 0){//right
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i-1][j+1]));
        }
        if(ck && !vst[{i-1,j}]) sum++,vst[{i-1,j}] = true;
    }
    if(i+1 < N && data[i+1][j] == 0){//down
        //now (i+1,j)
        ck = false;
        if(i+2 < N && dp[i+2][j] < 0){//down
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i+2][j]));
        }
        if(j-1 >=0 && dp[i+1][j-1] <0){//left
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i+1][j-1]));
        }
        if(j+1 < M && dp[i+1][j+1] < 0){//right
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i+1][j+1]));
        }
        if(ck && !vst[{i+1,j}]) sum++,vst[{i+1,j}] = true;
    }
    if(j+1 < M && data[i][j+1] == 0){//right
        //now (i,j+1)
        ck = false;
        if(i+1 < N && dp[i+1][j+1] < 0){//down
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i+1][j+1]));
        }
        if(i-1 >=0 && dp[i-1][j+1] <0){//top
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i-1][j+1]));
        }
        if(j+2 < M && dp[i][j+2] < 0){//right
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i][j+2]));
        }
        if(ck && !vst[{i,j+1}]) sum++,vst[{i,j+1}] = true;
    }
    if(j-1 >=0 && data[i][j-1] == 0){//left
        //now (i,j-1)
        ck = false;
        if(i+1 < N && dp[i+1][j-1] < 0){//down
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i+1][j-1]));
        }
        if(i-1 >=0 && dp[i-1][j-1] <0){//top
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i-1][j-1]));
        }
        if(j-2 >= 0 && dp[i][j-2] < 0){//left
            ck = true;
            stp = min(stp,dp[i][j]+(-1 * dp[i][j-2]));
        }
        if(ck && !vst[{i,j-1}]) sum++,vst[{i,j-1}] = true;
    }
}

int main( ){
    cin>>N>>M;
    dp = vector<vector<int>>(N,vector<int>(M,0));
    cin>>is>>js>>ie>>je;
    is--;
    js--;
    ie--;
    je--;
    FOR(i,0,N) FOR(j,0,M) cin>>data[i][j];
    BFS(is,js);
    BFS2(ie,je);
    // FOR(i,0,N){
    //     FOR(j,0,M){
    //         cout<<dp[i][j]<<'\t';
    //     }
    //     cout<<'\n';
    // }

    cout<<sum<<'\n'<<stp+1;
    return 0;
}
/*

*/