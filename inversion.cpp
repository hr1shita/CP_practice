//Counting inversions in an subarrays
//Given an array arr[], the goal is to count the number of inversions in all the sub-arrays. An inversion is a pair of indices i and j such that i > j and arr[i] < arr[j]. A sub-array from index x to y ( x<= y) consists of the element’s arr[x], arr[x+1], …, arr[y]. The array arr[] can also contain repeated elements.
#include <bits/stdc++.h>
using namespace std;
 
// Function to count the number of
// inversions in all the sub-arrays
void findSubarrayInversions(int arr[], int n)
{
 
    int inversions[n][n];
 
    // Initializing the inversion count
    // of each subarray to 0
    // inversions[i][j] will denote
    // the number of inversions
    // from index i to index j inclusive
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inversions[i][j] = 0;
        }
    }
 
    // Generating all subarray
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int ans = 0;
            // counting the number of inversions
            // for a subarray
            for (int x = i; x <= j; x++) {
                for (int y = x; y <= j; y++) {
                    if (arr[x] > arr[y])
                        ans++;
                }
            }
 
            inversions[i][j] = ans;
        }
    }
 
    // Printing the number of inversions
    // of all subarrays
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << inversions[i][j] << " ";
        }
        cout << "\n";
    }
}
 
// Driver Code
int main()
{
 
    // Given Input
    int n = 7;
    int arr[n] = { 3, 6, 1, 6, 5, 3, 9 };
 
    // Function Call
    findSubarrayInversions(arr, n);
}
