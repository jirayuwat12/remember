<<<<<<< HEAD
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
    string s;
    cin>>s;
    vector<int> dp(s.length( ),20);
    vector<pair<int,int>> q;
    int prim = 0;

    FOR(i,0,s.length( )) {
        if      (s[i] >='1' && s[i] <= '3') q.push_back({s[i]+prim,i});
        else if (s[i] =='[') prim += 3;
        else if (s[i] ==']') prim -= 3;
    }
    sort(q.begin( ),q.end( ),[](auto i,auto j){
        if(i.first==j.first) return i.second < j.second;
        return i.first > j.first;
    });
    map<int,bool> vst;
    for(auto it : q){
        int i  = it.second;
//cout<<it.first<<' '<<i<<" : ";
        double prc;
        if(s[i]=='1') prc = 0.04;
        else if(s[i]=='2') prc = 0.08;
        else prc = 0.16;
        vst[i] = true;
        vst[i-1] = true;
        vst[i+1] = true;
        int sum = dp[i-1] + dp[i+1]  + (int)((double)(dp[i-1] + dp[i+1])*prc);
        
        int ind = i;
        while(vst[ind-1] && ind-1 >= 0) dp[ind] = sum,ind--;
        if(s[ind-1]=='[') dp[--ind] = sum;

        vst[ind] = true;
        dp[ind] = sum;

        ind = i;
        while(vst[ind+1] && ind+1 < s.length( )) dp[ind]=sum,ind++;
        if(s[ind+1] ==']') dp[++ind] = sum;

        vst[ind] = true;
        dp[ind] = sum;


//for(int i :dp) cout<<i <<' ';
//cout<<'\n';
    }  
    cout<<*max_element(dp.begin( ),dp.end( )); 
    return 0;
}
/*
A2[A3A2[A2A]]

=======
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
    string s;
    cin>>s;
    vector<int> dp(s.length( ),20);
    vector<pair<int,int>> q;
    int prim = 0;

    FOR(i,0,s.length( )) {
        if      (s[i] >='1' && s[i] <= '3') q.push_back({s[i]+prim,i});
        else if (s[i] =='[') prim += 3;
        else if (s[i] ==']') prim -= 3;
    }
    sort(q.begin( ),q.end( ),[](auto i,auto j){
        if(i.first==j.first) return i.second < j.second;
        return i.first > j.first;
    });
    map<int,bool> vst;
    for(auto it : q){
        int i  = it.second;
//cout<<it.first<<' '<<i<<" : ";
        double prc;
        if(s[i]=='1') prc = 0.04;
        else if(s[i]=='2') prc = 0.08;
        else prc = 0.16;
        vst[i] = true;
        vst[i-1] = true;
        vst[i+1] = true;
        int sum = dp[i-1] + dp[i+1]  + (int)((double)(dp[i-1] + dp[i+1])*prc);
        
        int ind = i;
        while(vst[ind-1] && ind-1 >= 0) dp[ind] = sum,ind--;
        if(s[ind-1]=='[') dp[--ind] = sum;

        vst[ind] = true;
        dp[ind] = sum;

        ind = i;
        while(vst[ind+1] && ind+1 < s.length( )) dp[ind]=sum,ind++;
        if(s[ind+1] ==']') dp[++ind] = sum;

        vst[ind] = true;
        dp[ind] = sum;


//for(int i :dp) cout<<i <<' ';
//cout<<'\n';
    }  
    cout<<*max_element(dp.begin( ),dp.end( )); 
    return 0;
}
/*
A2[A3A2[A2A]]

>>>>>>> b3fc31d7ae480b3531ec5a3fc97cd836b469c2f6
*/