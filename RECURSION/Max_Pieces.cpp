#include<bits/stdc++.h>
using namespace std ;

int solve ( int n  , int a,  int b ,  int c ) 
{
     if ( n == 0 ) 
     {
          return  0 ;
     }
     else if ( n < 0 )
     {
          return -1;
     }

     int res = max ( solve( n -a , a, b , c)  , max  ( solve( n - b , a , b , c) , solve(  n -c ,  a , b , c)  ) );

     if( res == -1 ) 
     {
          return -1;
     }
     else 
     {
          return res + 1 ;
     }
}



int main ()
{
     int n  = 5 ;
     
     int a =  2 , b = 5 , c = 1 ;

     cout << solve( n ,  a , b , c ) << endl; 
 
     return 0 ;
}