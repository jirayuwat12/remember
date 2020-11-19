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
#include <limits>
#include <utility>
#include <math.h>
using namespace std;
#define FOR(i,s,n) for(int i =s;i<n;i++)
#define FORR(i,s,n) for(int i =s;i>=n;i--)
typedef long long ll;

double number_of_sold_books(double book_printed,double sell_price){
    return (((100 - (0.8569 * pow(2.718282,(0.09*(sell_price - 100.0 ))))) * book_printed ) / 100.0);
}

int main( ){
    
    double C;
    cin>>C;
    
    double outcome;
    double profit = numeric_limits<double>::max( );
    double income;

    double real_printed,real_sell_price;

    for(double sell_price = 74 ; sell_price <= 144; sell_price +=1 ){
        double book_base_price = 100;
        for(double book_printed = 1000 ; book_printed <= 15000 ; book_printed += 500){
            income = (number_of_sold_books(book_printed,sell_price) * sell_price);
            // cout<<income<<'\n';
            outcome = C + (book_base_price*book_printed);
            if(profit > income - outcome && income - outcome > 0){
                profit = income - outcome;
                real_printed = book_printed;
                real_sell_price = sell_price;
            } 
            book_base_price -= 1;
        }
    }
    
    printf("%.0f\n%.0f\n%.2f",real_printed,real_sell_price,profit);
    return 0;
}
/*

*/