#include <bits/stdc++.h>
#define FOR(i,s,n) for(int i=s;i<n;i++)
using namespace std;
/*
5 5
. . . . .
. . . O .
. O . . .
. . . O .
. . . . .
1 1 3 1 1
*/
int main(){
  int m,n;
  cin>>n>>m;
  char db[n][m];
  char t;
  FOR(i,0,n){
    FOR(j,0,m){
      cin>>t;
      db[i][j] = t;
    }
  }
  int brick[m];
  FOR(i,0,m) cin>>brick[i];
  FOR(i,0,m){
    int y=-1;
    while(db[y+1][i] == '.' && y < n-1) y++;
    if(y != -1) FOR(j,0,brick[i]) if(y-j >=0) db[y-j][i] = '#';
  }
  FOR(i,0,n){
    FOR(j,0,m){
      cout<<db[i][j];
    }cout<<endl;
  }
}
