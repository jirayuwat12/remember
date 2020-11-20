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

pair<int,string> return_real_bit(int nownode,string code){
    int return_node;
    string real_bit;

    if(nownode == 1 ) {
        if(code == "00"){
            return_node =1;
            real_bit = "0";
        }else{
            return_node =3;
            real_bit = "0";
        }
    }else if(nownode == 2){
        if(code == "11"){
            return_node =1;
            real_bit = "1";
        }else{
            return_node =3;
            real_bit = "1";
        }
    }else if(nownode == 3){
        if(code == "01"){
            return_node =4;
            real_bit = "0";
        }else{
            return_node =2;
            real_bit = "0";
        }
    }else if(nownode == 4){
        if(code == "10"){
            return_node =4;
            real_bit = "1";
        }else{
            return_node =2;
            real_bit = "1";
        }
    }

    return {return_node,real_bit};
}

string converts_ans(string ans){
    string new_ans = "";
    vector<string> split;
    string temp = "";
    int N = ans.length( );
    FOR(i,1,N+1){
        if(i == N) split.push_back(temp);
        else{
            if(ans[i]==' ') {
                split.push_back(temp);
                temp ="";
            }else{
                temp += ans[i];
            }
        }
    }
    int t[] = {0,64,32,16,8,4,2,1};
    for(string i : split) {
        int sum = 64;
        FOR(j,2,8){
            if(i[j] == '1') sum += t[j];
        }
        new_ans += (char)(sum);
    }

    return new_ans;
}

int main( ){
    int N;
    cin>>N;
    string ans = "";
    vector<string> data(N);
    while(--N >= 0){
        cin>>data[N];
    }
    int nownode = 1;

    if(data[0].length( ) != 16){
        for(int i = data[0].length( )-2 ;i>=0;i-=2){
            string string_temp = "";
            FOR(j,i,i+2) string_temp += data[0][j];
            pair<int,string> temp = return_real_bit(nownode,string_temp);
            nownode = temp.first;
        }
        // cout<<nownode<<'\n';
        FOR(i,1,data.size( )){
            for(int j = 14;j>=0;j-=2){
                string string_temp = "";
                FOR(k,j,j+2) string_temp += data[i][k];
                pair<int,string> temp = return_real_bit(nownode,string_temp);
                nownode = temp.first;
                ans += temp.second;
            }
            ans += ' ';
        }
    }else{
        FOR(i,0,data.size( )){
            for(int j = 14 ;j>=0;j-=2){
                string string_temp = "";
                FOR(k,j,j+2) string_temp += data[i][k];
                pair<int,string> temp = return_real_bit(nownode,string_temp);
                nownode = temp.first;
                ans += temp.second;
            }
            ans += ' ';
        }
    }
    reverse(ans.begin( ),ans.end( ));
    // cout<<ans<<' ';
    ans = converts_ans(ans);
    cout<<ans;
    return 0;
}
/*

*/