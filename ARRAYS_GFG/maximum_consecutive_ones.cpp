#include<bits/stdc++.h>
using namespace std ;


int get_max_consecutive_ones ( int arr[] , int  n )
{    
     int idx = 0 ;
     int no_of_ones = 0 ;
     int max_ones = INT_MIN;
     for( idx = 0 ; idx < n  ; idx ++ )
     {
          if ( arr [ idx ] == 0 )
          {
               no_of_ones = 0;
          }
          else 
          {
               no_of_ones ++;
               max_ones  = max( max_ones , no_of_ones ) ; 
          }
          
     }

     return max_ones ; 
}

int main ()
{
     int arr[] = { 0 , 1 , 1, 1 ,1 ,1 } ;
     int n = 6 ;
     cout << get_max_consecutive_ones ( arr , n ) << endl;
     return 0;
}