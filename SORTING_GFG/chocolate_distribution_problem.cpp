#include<bits/stdc++.h>
using namespace std ;




int distribute_chocolates( int arr[] , int n  , int no_of_students )
{
     if ( no_of_students >  n )    
          return INT_MAX;

     sort ( arr ,  arr+n);  

     int min_val = INT_MAX ;

     for( int idx = 0 ; ( idx + no_of_students  -1 )<n ; idx++  )
     {
          int first_val = arr [ idx];
          int last_val =  arr[ idx + no_of_students -1 ];
          int differ = abs( last_val - first_val );
          min_val = min ( min_val , differ);
     }

     return min_val;

}


int main ()
{
     int arr[] = { 2,3,4,7,9,12,56};
     int n  = 7 ;
     int no_of_students = 5;
     cout << distribute_chocolates( arr,n , no_of_students ) ;
     return 0 ;
}