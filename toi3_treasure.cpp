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
#include <math.h>
using namespace std;

#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;
int main( ){
    string n;
    double x =0,y=0;
    while(1){
        cin>>n;
        if(n == "*") break;
        double d =0;
        int l = n.length( )-1;
        int i = 0;
        while(n[i] >= '0' && n[i] <= '9'){
            d *= 10;
            d += (n[i]-'0');
            i++;
        }
        // cout<<'-'<<d<<'-';
        if(n[l] == 'N') y += d;
        else if(n[l] == 'S') y -= d;
        else if(n[l] == 'W') {
            if(n[l-1] == 'S'){
                d = (sqrt(2)/2.0)*d;
                y -= d;
                x -= d;
            }else if(n[l-1] == 'N'){
                d = (sqrt(2)/2.0)*d;
                y += d;
                x -= d;
            }else{
                x -= d;
            } 
        }else if(n[l] == 'E'){
            if(n[l-1] == 'S'){
                d = (sqrt(2)/2.0)*d;
                y -= d;
                x += d;
            }else if(n[l-1] == 'N'){
                d = (sqrt(2)/2.0)*d;
                y += d;
                x += d;
            }else{
                x += d;
            }
        }
    }
    // cout<<x<<' '<<y<<'\n'<<sqrt((x*x)+(y*y));
    printf("%.3f %.3f\n%.3f",x,y,sqrt((x*x+y*y)));
    return 0;
}
/*

*/