// A program to find nim-game winner
//You are given an array A[] of n-elements. There are two players Alice and Bob. A Player can choose any of element from array and remove it. If the bitwise XOR of all remaining elements equals 0 after removal of selected element, then that player loses
#include <bits/stdc++.h>
using namespace std;
 
// function to find winner of NIM-game
string findWinner(int A[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= A[i];
 
    // case when Alice is winner
    if (res == 0 || n % 2 == 0)
        return "Alice";
 
    // when Bob is winner
    else
        return "Bob";
}
 
// driver program
int main()
{
    int A[] = { 1, 4, 3, 5 };
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Winner = " << findWinner(A, n);
    return 0;
}
