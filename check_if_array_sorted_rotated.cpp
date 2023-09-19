//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    
    bool check_dsc( int arr[] , int n  ){
        int k = 0 ; 
         
         int count = 0 ; 

        int i ; 

        for ( i = 0 ; i < n-1 ; i ++ )
        {
               if ( arr [ i ]  <  arr [  (i + 1) % n ] ) 
               {    
                    k++;
               }
        }
     
        for ( i  = 0 ; i < n-1 ; i ++ )
     {
          if ( arr [ i ]  > arr [ (i + 1 )])
          {
               count ++;
          }
     }

     if( count + 1 == n )
     {
          return false ;
     }    

     if ( k > 1 )
     {
          return false;
     }

     return true;

    }
    
    bool check_asc (int arr[] , int n )
    {
          int i  , k = 0 , count = 0 ;

          for ( i = 0 ; i < n ; i ++ )
          {
               if (  arr [ i ] > arr [  ( i + 1) % n  ] ) 
               { 
                    k ++;
               }
          }

          for( i  = 0 ; i < n-1 ; i ++ )
          {
               if ( arr [ i ]  < arr [ i + 1 ] ) 
               {
                    count ++; 
               }
          }
        
          if ( count + 1 == n ||  k > 1 ) 
               return false; 
    
          else 
               return true;
}

    
    // arr: input array
    // num: length of array
    // This function returns true or false
    //Function to check if array is sorted and rotated.
    bool checkRotatedAndSorted(int arr[], int num){
        
        if ( check_asc( arr , num ) or  check_dsc( arr , num ) ) 
        {
            return true ;
        }
        
        return false; 
    }
};

//{ Driver Code Starts.

int main()
 {
     Solution obj;

     int arr [ ] = { 3 , 4, 1,  2 } ; 

     int n =  4 ; 

     cout << obj.checkRotatedAndSorted( arr , n )  << endl;

	return 0;
}
// } Driver Code Ends