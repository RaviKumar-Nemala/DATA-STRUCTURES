#include<bits/stdc++.h>
using namespace std ;

int  get_max_profit ( vector< int > &wt, vector< int >  &val ,  int max_wt , int n  ) 
{
     if ( n==0   or max_wt ==  0 ) 
     { 
          return  0 ; 
     } 
     if ( wt [ n - 1 ] <= max_wt )
     {
          return max( val[ n-1 ] + get_max_profit ( wt , val , max_wt - wt [ n - 1 ] ,  n -1 ) , get_max_profit( wt , val  , max_wt , n -1 ) ) ;
     }
     else 
     {
          return get_max_profit ( wt , val , max_wt ,  n - 1 ) ; 
     }

}

int dp [ 100 ] [ 100  ] ;

void initialize( )
{
     int i , j ; 
     for ( i = 0 ; i < 100 ; i ++ )
     {
          for ( j =  0 ; j < 100 ; j ++ )
          {
               dp [  i ] [ j ] = -1 ;
          }
     }
}

int knapsack_memoziation ( vector <int > &wt , vector < int > &val , int max_wt , int n ) 
{
     if ( n == 0 or  max_wt == 0 ) 
          return 0 ;
     
     if ( dp [ n -1 ] [ max_wt ] != -1 )
     {
          return dp [ n -1 ] [ max_wt ] ; 
     }

     int x ; 
     if ( max_wt >= wt [ n -1  ] )
     {    
          x = max( val [ n -1 ] + knapsack_memoziation ( wt , val , max_wt - wt [ n -1 ] , n -1 ) ,  knapsack_memoziation( wt , val , max_wt ,  n  -1 ) );
     }
     else if( max_wt < wt [ n -1 ] ) 
     {
          x  = knapsack_memoziation( wt , val , max_wt ,  n -1 ) ; 
     }
     cout << "x  = " << x << endl; 
     dp [ n -1 ] [ max_wt ] =  x ; 

     return dp [ n -1 ] [ max_wt ] ;
}

int main ()
{
     vector <int > wt = {  1 , 3, 4 , 5 } ;

     vector< int> val =  { 1 , 4 , 5,  7 } ; 
     
     int max_wt  = 7 ; 
     
     // initialize ( ) ; 

//     int temp =  get_max_profit ( wt , val , max_wt , last_idx) ; 
     int temp = knapsack_memoziation ( wt , val , max_wt,  wt.size () ) ; 

     cout << temp << endl;
}