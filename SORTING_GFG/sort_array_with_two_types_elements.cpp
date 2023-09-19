#include<bits/stdc++.h>
using namespace std ;

void lamuto_partition( int arr[] , int low, int high )
{
     int pivot = arr [ high ] ;
     int i = low -1 ;
     for( int j = low ; j <= ( high -1 ) ; j ++ )
     {
          if ( arr [ j ] < 0 )
          {
               i ++;
               swap( arr [ i ] , arr [ j ] ) ; 
          }
     }
     swap( arr [ i +1 ] ,  arr[high]);

     return;
}

void solve( int arr[]  , int n )
{
     lamuto_partition ( arr , 0 , n -1 );

     return;
}

void print_val( int arr[] , int n )
{
     for( int idx =  0 ; idx<  n ; idx++ )
     {
          cout << arr [ idx ] <<" " ; 
     }
     cout << endl;
}

int main ()
{
     int arr[] = {-10,-11,40,30,-1,-2};
     //we need to put the negative values at left and +Ve values at right
     // if we use the sort takes ( 0nlogn)
     //here +ve elements are may not be in the same order( sorted) 
     //so we simply use the lamuto or hoare partition
     
     int n = 6;
     solve(arr ,6);
     print_val( arr , n ) ;
     return 0 ; 
}