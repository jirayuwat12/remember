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
int main( ){
    int N,M,X;
    cin>>N>>M>>X;

    vector<int> L(N);
    for(auto &it : L) cin>>it;

    vector<int> A(N);
    for(int &it : A) cin>>it;
    sort(A.begin( ),A.end( ));

    vector<int> S(M+1);
    S[0] = 0;
    FOR(i,1,M+1) {
        cin>>S[i];
        S[i] += S[i-1];
    }

    vector<int> T(X);
    for(int &it :T) cin>>it;

    for(int maxtime : T){
        vector<int> Q(N);
        for(int &it : Q) cin>>it;
        vector<int> tA(N);
        FOR(i,0,N) tA[i] = A[i];
        FOR(i,0,N){
            int start = Q[i] -1;
            int stop = (i+1 < N)?Q[i+1]-1:M-1;
            int indexA = 
            bool status = false;
            while(!status){
                
            }
        }
    }
    return 0;
}
/*

*/