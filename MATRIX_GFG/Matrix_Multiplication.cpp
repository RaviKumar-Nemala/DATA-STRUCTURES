//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to multiply two matrices.
    vector<vector<int> > multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        //first arr col size should be same the second arr row size 
          
        int r1 = A .size () ;

        int r2 = B.size () ;
        
        int c1 = A [ 0 ] .size () ;

        int c2 =  B [ 0 ].size() ;

          if ( c1 != r2 )     return { {  }   } ; 

     vector< vector < int >  > res ( r1  ,  vector <int >  ( c1 ) ); 

     int i , j  , k ;

     for ( i  = 0 ; i < r1 ; i ++ )
     {
          for( j = 0 ;  j < r2 ; j ++ )
          {
               int total = 0 ;
               for(  k = 0 ; k < c1 ; k ++ )
               {
                    total += ( A [ i] [ k ] * B [ k] [ j ] ) ;
               }
               res [ i ] [ j ] = total;
          }
     }
     return res
    }
};


//{ Driver Code Starts.

int main() {

     vector <vector < int >  > A  = { { 4 , 8 } , { 0 , 2 } , { 1 ,  6 } } ;

     vector<vector < int > > B  = {  { 5 , 2 } , { 9 ,4 } } ; 
     
     Solution obj;

     obj.multiplyMatrix( A , B) ; 

     return 0;
}
// } Driver Code Ends