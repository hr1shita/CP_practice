/*Maximize the rightmost element of an array in k operations in Linear Time*/
#include <iostream>
using namespace std;
 
// Function to calculate maximum value of
// Rightmost element
void maxRightmostElement(int N, int k, int p, int arr[]){
   
     // Calculating maximum value of
     // Rightmost element
     while(k)
         {
        
          for(int i=N-2;i>=0;i--)
              {
             
                // Checking if arr[i] is operationable
                if(arr[i]>= p)
                  {
                      // Performing operation of i-th element
                      arr[i]=arr[i]-p;
                   
                      arr[i+1]=arr[i+1]+p;
                   
                      break;
                   
                  } 
             
              }
        
         // Decreasing the value of k by 1
         k--;
        }
   
        // Printing rightmost element
        cout<<arr[N-1]<<endl;
}
 
// Driver Code
int main() {
     
    // Given Input
    int N = 4, p = 2, k = 5, arr[] = {3, 8, 1, 4};
   
    // Function Call
    maxRightmostElement(N, k, p, arr);
    return 0;
}
