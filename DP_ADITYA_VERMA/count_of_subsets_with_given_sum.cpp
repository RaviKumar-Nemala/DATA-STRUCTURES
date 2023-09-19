#include<bits/stdc++.h>
using namespace std ;


void solve (vector <int> arr  , int sum ) 
{    
     int n = arr.size () ; 

     int dp [ n + 1 ] [  sum + 1 ] ;

     int i , j; 

     for (  i   = 0 ;i  <= n ; i ++ )
     {
          for(  j  = 0 ; j <= sum ; j ++ )
          {
               if  (  i == 0  and   j == 0 )
               {
                    dp [ i ] [ j ] = 1 ; 
               }   
               else if ( i == 0 )
               {
                    dp  [ i ] [ j ] =   0 ;
               }
               else if ( j == 0 )
               {
                    dp [ i ] [ j ] =  1 ; 
               } 
               else 
               {
                    if ( j >= arr [ i -1 ] ) 
                    {
                         dp [ i ] [ j ] = dp [ i -1 ] [ j - arr [  i -1 ] ]  + dp [ i -1 ] [ j ] ;  
                    }
                    else 
                    {
                         dp [ i ] [ j ] =  dp [ i -1 ]  [ j ] ; 
                    }
               }   
          }

     }
     cout << dp [ n ][  sum ] << endl; 

}

int main()
{
     vector<int > arr = { 2, 3,   5 , 6 ,  8 , 10};

     int sum =  10;

     solve( arr , sum ) ;

     return 0 ; 
}