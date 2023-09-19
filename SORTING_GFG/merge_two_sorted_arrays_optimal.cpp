//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
          { 
               int  i , j ;

               i = m - 1 ;

               for( i =  m -1 ; i >=0 ;  i -- )
               {
                    j = n - 2 ;
               
                    int last = arr1 [  n-1 ] ;

                    while ( j >= 0 and arr1[ j ] > arr2[ i ])
                    {
                         arr1[ j + 1 ] = arr1[ j ];
                         j --;
                    }
                    if( j !=( n-2) )
                    {
                         arr1[j +1] = arr2 [ i ] ; 
                         arr2[i] =  last;
                    }
               }

               for(  i  = 0 ; i < n ; i ++ )
               {
                    cout << arr1[ i ] << " " ; 
               }
               cout <<endl;
               for ( i = 0 ; i < m ; i ++ )
               {
                    cout << arr2 [  i ] << " " ; 
               }cout << endl;
          } 
};

//{ Driver Code Starts.

int main() 
{ 
     long long n = 4, arr1[] = {1 , 3 , 5 , 7} ;
     long long  m = 5, arr2[] = {0  ,2  ,6  , 8  ,9};
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

	return 0; 
} 

// } Driver Code Ends