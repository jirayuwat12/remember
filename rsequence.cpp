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
#include <stack>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
int n;
int data[500000];
int sum = 0;
int main( ){
    cin>>n;
    FOR(i,0,n) cin>>data[i];
    FOR(i,0,n){
        for(int j = i+1;j<n;j+=2){
            stack<int> st;
            FOR(k,i,j+1){
                if(st.empty( )) st.push(data[k]);
                else if(st.top( ) == data[k]) st.pop( );
                else st.push(data[k]);
            }
            if(st.empty( )) sum++;
        }
    }
    cout<<sum;
    return 0;
}
/*
0 1 0 1 1 0 0 0 1
0 0 0 0 0 0 0 0 0
  1 1 1 1 1 1 1
    0 0 0   0
      1  
        1 0   0 1
        1 0   0 1
          1   0 0
          1   0 0
              1 0 
              1 0
                1
                1 
*/     