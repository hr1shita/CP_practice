/*Count of substrings in a Binary String that contains more 1s than 0s*/
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to merge two partitions
// such that the merged array is sorted
void merge(vector<int>& v, int left,
           int mid, int right, int& inversions)
{
    vector<int> temp(right - left + 1);
 
    int i = left;
    int j = mid + 1;
    int k = 0;
    int cnt = 0;
 
    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        }
        else {
            // Counting inversions
            inversions += (mid - i + 1);
 
            temp[k++] = v[j++];
        }
    }
 
    while (i <= mid)
        temp[k++] = v[i++];
 
    while (j <= right)
        temp[k++] = v[j++];
 
    k = 0;
    for (int a = left; a <= right; a++) {
        v[a] = temp[k++];
    }
}
 
// Function to implement merge sort
void mergeSort(vector<int>& v, int left,
               int right, int& inversions)
{
    if (left < right) {
        int mid = (left + right) / 2;
 
        mergeSort(v, left, mid, inversions);
        mergeSort(v, mid + 1, right, inversions);
        merge(v, left, mid, right, inversions);
    }
}
 
// Function to calculate number of
// inversions in a given array
int CountInversions(vector<int>& v)
{
    int n = v.size();
    int inversions = 0;
 
    // Calculate the number of inversions
    mergeSort(v, 0, n - 1, inversions);
 
    // Return the number of inversions
    return inversions;
}
 
// Function to count the number of
// substrings that contains more 1s than 0s
int getSubsCount(string& input)
{
    int n = input.length();
 
    vector<int> nums(n);
 
    for (int i = 0; i < n; i++) {
        nums[i] = input[i] - '0';
 
        if (nums[i] == 0)
            nums[i] = -1;
    }
 
    // Stores the prefix sum array
    vector<int> pref(n);
 
    int sum = 0;
 
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        pref[i] = sum;
    }
 
    int cnt = 0;
 
    // Stores the count of valid substrings
    for (int i = 0; i < n; i++) {
        if (pref[i] > 0)
            cnt++;
    }
 
    reverse(pref.begin(), pref.end());
 
    int inversions = CountInversions(pref);
 
    int ans = cnt + inversions;
 
    return ans;
}
 
// Driver Code
int main()
{
 
    // Given Input
    string input = "101";
 
    // Function Call
    int ans = getSubsCount(input);
 
    cout << ans << endl;
 
    return 0;
}
