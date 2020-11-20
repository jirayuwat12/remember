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
int K,M;
vector<string> pat;
bool found(string t,int target){
    int L,R;
    L = R = 0;
    int n = t.length( );
    vector<int>Z(n,0);
    FOR(i,1,n){
        if(i > R){
            L=R=i;
            while(R <n && t[R-L] == t[R]) R++;
            Z[i] = R-L; 
            R--;
        }else{
            int k = i-L;
            if(Z[k] <= R-i) Z[i] = Z[k];
            else{
                L=i;
                while(R<n && t[R-L]==t[R]) R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
    for(int i :Z) if(i==target) return true;
    return false;
}
int main( ){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string inp;
    cin>>K>>M;
    FOR(i,0,K){
        cin>>inp;
        pat.emplace_back(inp);
    }
    int t;
    cin>>t;
    while(t--){
        int d;
        cin>>d>>inp;
        bool ck = true;
        FOR(i,0,K){
            if(found(pat[i] + "$" + inp,pat[i].length( ))){
                cout<<i+1<<' ';
                ck = false;
            }
        }
        if(ck) cout<<"OK";
        cout<<'\n';
    }
    return 0;
}
/*

*/