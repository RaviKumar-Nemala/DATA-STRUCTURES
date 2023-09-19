#include<bits/stdc++.h>
using namespace std ;

class Solution 
{
public : 
 

     
     void solve ( vector< int >  coins  , int n , int required_sum  )
     {

          int dp [ n + 1 ] [ required_sum + 1 ] ;

          int i , j ; 

          for  ( i = 1 ; i <= n ; i ++ )
          {

               dp [  i ] [ 0 ] =  0 ;

          }

          for ( j =  0 ; j  <= required_sum ; j ++ )
          {
               dp [ 0 ] [ j ] = INT_MAX  - 1 ;
          }


          for (  j = 1 ; j   <= required_sum  ; j ++ )
          {

                    if ( j %coins [ 0 ] == 0 )
                    {
                         dp [ 1 ] [ j ] = j /  coins [ 0 ] ;
                    }
                    else 
                         dp  [ 1 ] [ j ] = INT_MAX - 1;

          }

          for  ( i = 2 ; i <=n ;  i ++ )
          {

               for ( j  = 0  ; j <= required_sum ; j ++ )
               {

                    
                    if (  j >= coins [ i -1 ] ) 
                    {
                         dp [ i ] [ j ] = min ( dp [ i - 1 ] [ j ] ,  1 + dp [ i ] [ j - coins [ i - 1 ] ] ) ;
                    }
                    else 
                    {
                         dp [ i ] [ j ] = dp [ i - 1 ] [ j ] ;
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




