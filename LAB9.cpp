/*
  Author: Alysa Liann Vega
  Course: CSCI-135
  Instructor: Tong Yi
  Date: March 28, 2022

  Lab 9: practicing dynamic allocation
*/

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *ppoem;      // declare a pointer to string
                        // (it will store the address)

    ppoem = new string; // <-- DYNAMICALLY ALLOCATE MEMORY
                        //     for a poem string and
                        //     store its address in the pointer

    *ppoem =            // put a poem there
      "   Those             \n"
      "   who can write     \n"
      "   have a            \n"
      "   lot to            \n"
      "   learn from those  \n"
      "   bright            \n"
      "   enough            \n"
      "   not to.           \n";

    return ppoem;       // return the address where the poem is
}

int main() {
    string * p;
    p = createAPoemDynamically();
    // The memory at the address p still stores the poem we
    // put in it during the function call. Neat!

    // At any later moment, you can print it out:
    cout << *p;

    // You can also save the address into another pointer variable:
    string *p2 = p;   // then both pointers, p and p2,
                      // will be pointing to the same poem.
    cout << *p2;
}

