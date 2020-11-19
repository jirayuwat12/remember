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
#include <stack>
#include <utility>
#include <map>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;

int N,M;
vector<vector<char>> data;
//      i           j       nr      ng    t
map<pair<int,pair<int,pair<int,int>>>,bool> vst;
int real_sum = -1;
string ans;
void find( ){
    stack<pair<int,pair<int,pair<int,pair<int,string>>>>> s;
    s.push({0,{0,{0,{0,"N"}}}});
    if(data[0][0]=='R') s.push({0,{0,{1,{0,"Y"}}}});
    else s.push({0,{0,{0,{1,"Y"}}}});
    while(!s.empty( )){
        int i = s.top( ).first;
        int j = s.top( ).second.first;
        int nr = s.top( ).second.second.first;
        int ng = s.top( ).second.second.second.first;
        string t = s.top( ).second.second.second.second;
        if(vst[{i,{j,{nr,ng}}}]) {
            s.pop( ) ;
            continue;
        }
        vst[{i,{j,{nr,ng}}}] = true;
        s.pop( );
        if(nr > (N+M+1)/2 || ng > (N+M+1)/2) continue;
        if(i == N-1 && j == M-1){
            if(nr == ng) {
                if(nr * 2 > real_sum){
                    real_sum = nr*2;
                    ans = t;
                }
            }
        }else{
            if(i+1 < N){
                //D
                if(data[i+1][j] == 'R') s.push({i+1,{j,{nr+1,{ng,t +"DY"}}}}),s.push({i+1,{j,{nr,{ng,t + "DN"}}}});
                else s.push({i+1,{j,{nr,{ng+1,t + "DY"}}}}),s.push({i+1,{j,{nr,{ng,t + "DN"}}}});
            }
            if(j+1 < M){
                //R
                if(data[i][j+1] == 'R') s.push({i,{j+1,{nr+1,{ng,t + "RY"}}}}),s.push({i,{j+1,{nr,{ng,t + "RN"}}}});
                else s.push({i,{j+1,{nr,{ng+1,t + "RY"}}}}),s.push({i,{j+1,{nr,{ng,t + "RN"}}}});
            }
        }
    }
}

int main( ){
    cin>>N>>M;
    data = vector<vector<char>>(N,vector<char>(M));
    FOR(i,0,N){
        string inp;
        cin>>inp;
        FOR(j,0,M){
            data[i][j] = inp[j];
        }
    }
    find( );
    cout<<real_sum<<'\n';
    int k = 1;
    for(char i : ans){
        if(k==1) cout<<i<<' ';
        else if(k == 2) cout<<i<<'\n',k=0;
        k++;
    }
    return 0;
}
/*

*/