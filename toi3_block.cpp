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
vector<vector<char>> data;
int m,n;

void setb(int i,int j){
    if(i-1 >= 0 && data[i][j] != '#' && data[i-1][j] != '#') {
        data[i][j] = data[i-1][j];
        data[i-1][j] = '-';
    }
}

int main( ){
    cin>>m>>n;
    data = vector<vector<char>>(m,vector<char>(n));
    FOR(i,0,m){
        FOR(j,0,n){
            cin>>data[i][j];
        }
    }
    int t;
    cin>>t;
    int sum = 0;
    while(t--){
        int i,j;
        char d;
        cin>>i>>j>>d;
        
        d = (d == 'L')?-1:1;
        if(data[i][j] == '#' || data[i][j] == '-' || data[i][j+d] != '-' ) sum -= 5;
        else{
            char temp =  data[i][j];
            data[i][j] = '-';
            setb(i,j);
            j += d;
            
            while(data[i+1][j] == '-') i++; 
            
            bool ck = true;
            if(temp == data[i][j+1]) {//right
                data[i][j+1] = '-';
                
                setb(i,j+1);
                
                sum +=5;
                ck = false;
            }
            if(temp == data[i][j-1]) {//left
                data[i][j-1] = '-';

                setb(i,j-1);
                
                sum +=5;
                ck = false;
            }
            if(temp == data[i+1][j]) {//below
                data[i+1][j] = '-';
                sum +=5;
                ck = false;
            }
            if(ck){
                data[i][j] = temp; 
                sum -=5;
            }else sum +=5;
        }
    }
    cout<<sum<<'\n';
    FOR(i,0,m){
        FOR(j,0,n){
            cout<<data[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
/*

*/