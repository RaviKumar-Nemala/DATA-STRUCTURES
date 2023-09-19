#include<bits/stdc++.h>
using namespace std ;

void min_coins( vector< int > arr , int sum )
{
     int  n = arr.size() ; 

     vector <  vector< int > >  dp ( n+1 ,  vector< int >(  sum + 1 )) ;

     int i , j ;

     for( i =  0 ; i <= sum ; i ++ )
     {
          dp [ 0] [ i ] =  INT_MAX -1 ;
     }

     for (  i =  1 ; i <= n ; i ++ )
     {
          dp [ i ] [ 0 ] = 0 ;
     }

     for ( i =  1 ; i <= n ; i ++ )
     { 
          for ( j = 1 ; j <= sum ; j ++ )
          {
               if ( i == 1 )
               {
                    if ( j % arr [ 0 ]== 0 ) 
                    {
                         dp [ i ] [ j ] =  j /  arr [ 0 ] ; 
                    }
                    else 
                    {
                         dp [ i ] [ j ] = INT_MAX - 1 ; 
                    }
               }    
               else  
               {
                    if (  arr [ i  - 1 ] <= j ) 
                    dp [ i ] [ j ] =  min ( 1 + dp [ i ][ j - arr [ i -1 ] ]  , dp [ i -1 ] [ j ] ); 
                    else 
                    dp [ i ] [ j ] =  dp [ i -1 ][ j ] ; 
               }
          }
     }

     for( i  = 0 ; i <= n ; i ++ )
     {
           for(  j = 0 ; j <= sum ; j ++ )
               cout << dp [ i ] [ j  ] <<" " ; 
          cout << endl;
     }


}

int main ()
{
     vector<int> arr = { 1 ,  2 , 3 } ; 

     int sum = 5 ; 

     min_coins( arr , sum ) ; 

}