//{ Driver Code Starts
//Initial Template for C++

// CPP code to find largest and 
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
     

class Solution{
  public:
    /* Function to find largest and second largest element
    *sizeOfArray : number of elements in the array
    * arr = input array
    */
    vector<int> largestAndSecondLargest(int n, vector < int > arr ){
          int max_idx = 0 ;

          int second_max_idx = -1;

          for( int i =  1 ; i < n ; i ++ )
          {
               int curr_val = arr [ i ] ; 

               if ( curr_val == arr  [ max_idx ] ) 
                    continue;
               
               else if ( curr_val >  arr [ max_idx ] )
               {
                    second_max_idx  = max_idx ;
                    max_idx = i ;
               }
               else  if ( second_max_idx == -1 || arr[ second_max_idx]  <curr_val)
               {
                         second_max_idx = i ; 
               }

          }

          cout  << max_idx <<" "  << second_max_idx << endl;
    }
};

//{ Driver Code Starts.

// Driver Code
int main() {

     vector < int > arr = { 1 , 2,  4 , 5,  6 } ;

     Solution obj;

     obj.largestAndSecondLargest( arr.size() ,  arr ) ;

	return 0;      
}
// } Driver Code Ends