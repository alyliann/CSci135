/*
 Author: Alysa Liann Vega
 Course: CSCI-135
 Instructor: Tong Yi
 Date: February 24, 2022
 Assignment: Lab 5
 
 This program uses functions to find various features of numbers (prime, twin prime, etc.).
 */

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d) {     //checks if n is divisible by d
    if (d == 0){
        return false;
    }
    else if (n % d == 0){
        return true;
    }
    else{
        return false;
    }
}

bool isPrime(int n){                    //checks if n is a prime number
    bool TorF = 0;
    if (n == 2){
        TorF = true;
    }
    else{
        for (int i = 2; i < n; i++){
            if (n % i == 0){
                TorF = false;
                break;
            }
            else{
                TorF = true;
            }
        }
    }
    return TorF;
}

int nextPrime(int n){                   //finds the smallest prime after n
    for (int i = (n+1); ; i++){
        bool prime = isPrime(i);
        if (prime == true){
            return i;
            break;
        }
    }
}

int countPrimes(int a, int b){          //counts the # of primes btwn a and b
    int count = 0;
    for (int i = a; i <= b; i++){
        bool prime = isPrime(i);
        if (prime == true){
            count += 1;
        }
    }
    return count;
}

bool isTwinPrime(int n){                //checks if n is a twin prime
    bool prime = isPrime(n);
    if (prime == true){
        bool beforePrime = isPrime(n-2);
        bool afterPrime = isPrime(n+2);
        if (beforePrime == true || afterPrime == true){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int nextTwinPrime(int n){               //finds the next twin prime after n
    for (int i = (n+1); ; i++){
        bool twinPrime = isTwinPrime(i);
        if (twinPrime == true){
            return i;
            break;
        }
    }
}

int largestTwinPrime(int a, int b){     //finds the largest twin prime btwn a and b
    for (int i = b; i >= a; i--){
        bool twin = isTwinPrime(i);
        if (twin == true){
            return i;
            break;
        }
    }
    return -1;
}

int main() {
    int int1, int2;                    //declare variables, obtain inpiuts
    cout << "Enter an integer: ";
    cin >> int1;
    cout << "Enter another integer: ";
    cin >> int2;
    
    /*Task A:
    bool TorF = isDivisibleBy(int1, int2);
    if (TorF == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    */
    
    /*Task B:
    bool prime = isPrime(int1);
    if (prime == true){
        cout << int1 << " is prime" << endl;
    }
    else{
        cout << int1 << " is not prime" << endl;
    }
    */
    
    /*Task C:
    int prime2 = nextPrime(int1);
    cout << prime2  << endl;
    */
    
    /*Task D:
    int primes = countPrimes(int1, int2);
    cout << "There are " << primes << " primes between " << int1 << " and " << int2 << endl;
    */
    
    /*Task E:
    bool twin = isTwinPrime(int1);
    if (twin == true){
        cout << int1 << " is a twin prime" << endl;
    }
    else{
        cout << int1 << " is not a twin prime" << endl;
    }
    */
    
    /*Task F:
    int twin2 = nextTwinPrime(int1);
    cout << twin2 << " is the next twin prime" << endl;
    */
    
    /*Task G: */
    int bigTwin = largestTwinPrime(int1, int2);
    cout << "The largest twin prime between " << int1 << " and " << int2 << " is " << bigTwin << endl;
    
    return 0;
}
