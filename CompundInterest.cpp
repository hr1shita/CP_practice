/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// C++ program to find compound interest for given fixed values
 
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    double principle = 10000, rate = 5, time = 2;
 
    /* Calculate compound interest */
    double A = principle * (pow((1 + rate / 100), time));
      double CI = A- principle;
 
    cout << "Compound interest is " << CI;
 
    return 0;
}
