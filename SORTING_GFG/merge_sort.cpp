#include<bits/stdc++.h>
using namespace std; 

void print_val( int arr[] ,   int n )
{
     for ( int idx = 0 ; idx < n ; idx++)
     {
          cout << arr [idx]<<" ";
     }
     cout <<endl;
}

void merge ( int[] , int , int ,  int ) ; 

void merge_sort( int arr[] , int  low   , int high )
{
     //when we only have one element then no need to sort
     // if we have more then one elment then only allow the merge sort
     if ( high >  low )
     {
          int mid_val = (low  + high )/2 ;
          
          merge_sort ( arr , low,  mid_val );

          merge_sort( arr , mid_val +1 , high ) ;

          merge ( arr , low , mid_val , high);

     }

}

void merge( int arr[] , int low , int mid , int high )
{
     int n1 = mid -low + 1 ;
     int n2 = high - mid ;
     
     int left [ n1 ] ;
     int right [ n2 ] ;

     for( int idx = 0 ; idx  < n1 ; idx ++)
     {
          left [ idx ] = arr [ low + idx ] ;
     }
     for ( int idx = 0 ; idx < n2 ; idx ++ )
     {
          right [ idx ] = arr [ mid  + 1 + idx ] ;
     }

     int idx_1 = 0 ,  idx_2 = 0 ;

     int k = low ; 

     while( idx_1 < n1 and idx_2 < n2 )
     {
          if (left[ idx_1 ]  < right [ idx_2 ])
          {
               arr[ k ++] = left [ idx_1 ++];
          }
          else 
          {
               arr [ k ++] = right [ idx_2 ++];
          }
     }

     while( idx_1 < n1 )
     {
          arr [ k++ ] =  left [ idx_1 ++ ];
     }
     while ( idx_2 < n2 )
     {
          arr[  k ++ ] = right [ idx_2 ++ ] ;
     }

     return ;
}

int main ()
{
     int arr[] = { 10,15,20,11,30};
     int n = 5;
     int low = 0 ; 
     int mid = 2;
     int high = 4;

     merge_sort ( arr , low , high );

     print_val( arr , n  ) ;
     return 0;
}