//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    {      
          int idx = 0 ; 

          long long temp =  arr[   n  - 1   ]  + 1 ; 
          
          int max_idx =  n -1 ;
          
          int min_idx = 0 ; 

          for ( idx = 0 ; idx < n ; idx ++ ) 
          {
               long long curr_val = arr [ idx ] ; 

               if  ( idx % 2 == 0 )
               {
                    arr [ idx ] =  ( curr_val +  ( arr [max_idx] % temp ) * temp );

                    max_idx --;
               }         
               else 
               {
                    arr [ idx ] = ( curr_val  +  ( arr [ min_idx] % temp ) * temp );

                    min_idx ++;
               } 
          }

          for  ( idx = 0 ; idx <  n  ; idx ++ ) 
          {    
               long long val  = arr [ idx ] ;

               arr [ idx ]  =  val  / temp ; 
          }

          return ;
    	 
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends