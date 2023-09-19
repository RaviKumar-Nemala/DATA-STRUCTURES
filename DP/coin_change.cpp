#include<bits/stdc++.h>
using namespace std ;

class Solution 
{
public : 
 

     
     void solve ( vector< int >  coins  , int n , int required_sum  )
     {

          int dp [ n + 1 ] [ required_sum + 1 ] ;

          int i , j ; 

          for  ( i = 0 ; i <= n ; i ++ )
          {

               dp [  i ] [ 0 ] =  1 ;

          }

          for (  j = 1 ; j   <= required_sum  ; j ++ )
          {

               dp [ 0 ][ j  ]  = 0 ; 

          }

          for  ( i = 1 ; i <=n ;  i ++ )
          {

               for ( j  = 1  ; j <= required_sum ; j ++ )
               {

                    if ( j >=coins [ i -1 ] ) 
                     {

                    dp [ i ] [ j ] = dp [ i ] [ j - coins[ i - 1 ] ]  + dp [ i -1 ] [ j ] ; 

                     }
                     else 
                     {
                         dp [ i ] [ j ] = dp [ i  - 1 ] [ j  ] ; 
                     }

               }

          }

          cout<< "NO OF WAYS :  " << dp [ n  ] [ required_sum ] ; 
          
     }





};

int main () 
{

vector< int > coins = { 1, 2, 3 }  ; 

int required_sum  = 5 ;

Solution obj ;

int  n   = 3 ;

obj.solve  ( coins ,  n  , required_sum ) ; 





}




