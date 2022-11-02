//Author: Alysa Liann Vega
//Course: CSCI-135
//Instructor: Tong Yi
//Date: April 21, 2022
//Assignment: Lab Quiz 12

//Define class Money with public int data members dollars and cents. Define NON member function Money add_money(Money x, Money y) where cents of added result is < 100.

#include <iostream>
using namespace std;

class Money{
public:
    int dollars;
    int cents;
};

Money add_money(Money x, Money y){
    int dols, cens;
    
    if (x.cents + y.cents >= 100){
        cens = (x.cents + y.cents) - 100;
        dols = 1 + x.dollars + y.dollars;
    }
    else {
        dols = x.dollars + y.dollars;
        cens = x.cents + y.cents;
    }
    return {dols, cens};
}

int main(){
    
    Money total = add_money({3, 56}, {2, 50});
    
    if (total.cents < 10)
        cout << "$" << total.dollars << ".0" << total.cents << endl;
    else
        cout << "$" << total.dollars << "." << total.cents << endl;
    
    return 0;
}
