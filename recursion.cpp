/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: May 2, 2022
Assignment: Lab 13

This program uses recursion to print all numbers in range left ≤ x ≤ right, separated by spaces.
*/

#include <iostream>
#include <cctype>
using namespace std;

//Task A:
void printRange(int left, int right){
    
    if (left < right)
        cout << left << " ";
    else if (left == right)
        cout << left << endl;
    
    if (left < right)          //keeps adding one to left until left == right
        printRange(left+1, right);
}

//Task B:
int sumRange(int left, int right){
    
    int sum = 0;
    sum += right;
    
    if (right != left-1)
        return sum + sumRange(left, right-1);       //adds back from right

    return 0;
}

//Task C:
int sumArray(int *arr, int size){
    
    int sum = 0;
    sum += arr[size-1];
    
    if (size != 0)
        return sum + sumArray(arr, size-1);       //adds backward from arr[size-1]
    return 0;
}

//Task D:
bool isAlphanumeric(string s){
    
    bool b;
    
    if (s.length() == 0)            //if string empty return true
        b = true;
    else {
        if (!isdigit(s[0]) && !isalpha(s[0])){     //if digit is not alphanumeric
            return false;
        }
        else if ((isdigit(s[0]) || isalpha(s[0])) && s.length() > 0){
            b = true;
            return isAlphanumeric(s.substr(1, s.length()-1));
        }
    }
    
    return b;
}

//Task E (bonus):
bool nestedParens(string s){
    
    /*cout << endl << "new: ";
    for (int i = 0; i < s.length(); i++){
        cout << s[i];
    }*/
    
    bool b;
    
    if (s.length() == 0)
        b = true;
    else{
        if (s[0] != '(' || s[s.length()-1] != ')')  //first and last dont match
            return false;
        else if (s.length() % 2 != 0)   //odd num of characters in string
            return false;                   //implies parens dont match up
        else if (s.length() > 2){
            return nestedParens(s.substr(1, s.length()-2));
            
        }
    }
    
    b = true;
    return b;
}

//Task F (bonus):
int minElemArr(int *arr, int size){                                             //helper func for divisible() func to find min val in array
    
    if (size != 1)
        return min(arr[size-1], minElemArr(arr, size-1));
    else
        return arr[0];

}

bool divisible(int *prices, int size){  //returns true if the collection is divisible, and false otherwise
    
    bool b;
    
    int sum = sumArray(prices, size);   //172 for example below
    
    if (sum % 2 != 0)
        return false;       //sum not divisible by 2
    
    int half = sum/2;
    int Alice, Bob;
    int min = minElemArr(prices, size);
    cout << "min: " << min;
    
    //check every element of array
        //for each element, check if you can give it to alice or bob (if neither, return false)
            //specifically, check if adding it to alice or bob exceeds half of sum
            //if no, check if it
    
    if ((Alice + prices[size-1] <= half && Alice + prices[size-1] < half-min) || (Bob + prices[size-1] <= half && Bob + prices[size-1] < half-min)){
        if (Alice + prices[size-1] <= half){
            Alice += prices[size-1];
            b = true;
        }
        else{
            Bob += prices[size-1];
            b = true;
        }
        return divisible(prices, int size-1);
    }
    else
        return false;
    
    return b;
}

int main(){
    
    int array[] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    
    divisible(array, 9);

}
