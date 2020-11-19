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
#include <set>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
vector<vector<int>> G('Z'+1,vector<int>('Z'+1,0));
vector<vector<int>> vst('Z'+1,vector<int>('Z'+1,0));
set<char> d;
int E;
string ans1 = "";
bool ck = false; 
void DFS(int start,int numpath = 0,string ans =""){
    ans += (char)start;
    if(numpath == E) ans1 = ans;
    if(ans1 != "") return;
    FOR(i,'A','Z'+1){
        if(G[start][i] && !vst[min(start,i)][max(start,i)]){
            vst[min(start,i)][max(start,i)] = true;
            DFS(i,numpath+1,ans);
            vst[min(start,i)][max(start,i)] = false;
        }
    }
}

int main( ){
    cin>>E;
    string inp;
    FOR(i,0,E){
        cin>>inp;
        d.insert(inp[0]);
        d.insert(inp[1]);
        G[inp[0]][inp[1]] = 1;
        G[inp[1]][inp[0]] = 1;
    }
    for(char i : d){
        DFS((int)i);
    }
    for(char i : ans1) {
        cout<<i<<' ';
    }
    return 0;
}
/*

*/